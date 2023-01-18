#include "pch.h"
#include "CustomerViewModel.h"
#if __has_include("CustomerViewModel.g.cpp")
#include "CustomerViewModel.g.cpp"
#endif

namespace winrt::FirstUWPApp01::implementation
{
    CustomerViewModel::CustomerViewModel() 
    {
        m_customer = make<FirstUWPApp01::implementation::Customer>(L"Atticus");
    }


    FirstUWPApp01::Customer CustomerViewModel::Customer()
    {
        return m_customer;
    }
}
