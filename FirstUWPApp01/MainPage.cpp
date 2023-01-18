#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::FirstUWPApp01::implementation
{
    FirstUWPApp01::CustomerViewModel MainPage::Model()
    {
        return m_model;
    }
    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        // myButton().Content(box_value(L"Clicked"));

        greetingOutput().Text(L"Hello, " + nameInput().Text() + L"!");
    }
}


void winrt::FirstUWPApp01::implementation::MainPage::inputButtonVM_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    Model().Customer().Name(L"Optimus Prime");

}
