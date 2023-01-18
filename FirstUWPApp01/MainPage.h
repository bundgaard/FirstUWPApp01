#pragma once

#include "MainPage.g.h"
#include "CustomerViewModel.h"

namespace winrt::FirstUWPApp01::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage()
        {
            m_model = make<FirstUWPApp01::implementation::CustomerViewModel>();
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        FirstUWPApp01::CustomerViewModel Model();
        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);

    private :
        FirstUWPApp01::CustomerViewModel m_model{nullptr};
    public:
        void inputButtonVM_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::FirstUWPApp01::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
