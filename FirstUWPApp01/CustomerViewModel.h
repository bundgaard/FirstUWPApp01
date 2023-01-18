#pragma once

#include "CustomerViewModel.g.h"
#include "Customer.h"
namespace winrt::FirstUWPApp01::implementation
{
    struct CustomerViewModel : CustomerViewModelT<CustomerViewModel>
    {
        CustomerViewModel();
        FirstUWPApp01::Customer Customer();
       
    private:
        FirstUWPApp01::Customer m_customer{ nullptr };
    };
}

namespace winrt::FirstUWPApp01::factory_implementation
{
    struct CustomerViewModel : CustomerViewModelT<CustomerViewModel, implementation::CustomerViewModel>
    {
    };
}
