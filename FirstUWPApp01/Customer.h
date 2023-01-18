#pragma once

#include "Customer.g.h"

namespace winrt::FirstUWPApp01::implementation
{
    struct Customer : CustomerT<Customer>
    {
        Customer() = delete;
        Customer(winrt::hstring const& name);
        
        winrt::hstring Name();
        void Name(winrt::hstring const& name);
   
        winrt::event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler handler);
        void PropertyChanged(winrt::event_token const& token);

    private:
        winrt::hstring m_name;
        winrt::event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}

namespace winrt::FirstUWPApp01::factory_implementation
{
    struct Customer : CustomerT<Customer, implementation::Customer>
    {
    };
}
