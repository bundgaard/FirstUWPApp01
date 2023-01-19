#pragma once

#include "MainPage.g.h"
#include "CustomerViewModel.h"

namespace winrt::FirstUWPApp01::implementation
{
	struct MainPage : MainPageT<MainPage>
	{
		MainPage();

		hstring FromBatteryStatus(Windows::System::Power::BatteryStatus status);
		FirstUWPApp01::CustomerViewModel Model();
		Windows::Devices::Power::Battery Battery();
		void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
		void InitializeComponent();

		void OnBatteryReport(Windows::Devices::Power::Battery const& battery, winrt::Windows::Foundation::IInspectable const& args);
	
	
	private:
		FirstUWPApp01::CustomerViewModel m_model{ nullptr };
		Windows::Devices::Power::Battery m_battery{ nullptr };
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
