#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::FirstUWPApp01::implementation
{
	MainPage::MainPage()
	{
		m_model = make<FirstUWPApp01::implementation::CustomerViewModel>();
		
		// OutputDebugString(FromBatteryStatus(report.Status()).c_str());
	

		// Xaml objects should not call InitializeComponent during construction.
		// See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
	}

	void MainPage::InitializeComponent()
	{
		MainPageT::InitializeComponent();
		auto report = Battery().GetReport();
		Battery().ReportUpdated({this, &MainPage::OnBatteryReport});

		batteryStatus().Text(FromBatteryStatus(report.Status()));
		batteryLevel().Value(report.RemainingCapacityInMilliwattHours().GetDouble());
	}

	void MainPage::OnBatteryReport(Windows::Devices::Power::Battery const& battery, winrt::Windows::Foundation::IInspectable const& args)
	{
		OutputDebugString(L"Onbattery report\n");
		const auto status = FromBatteryStatus(battery.GetReport().Status());
		batteryStatus().Text(status);
		
	}

	hstring MainPage::FromBatteryStatus(Windows::System::Power::BatteryStatus status)
	{
		switch (status)
		{
		case Windows::System::Power::BatteryStatus::NotPresent:
			return hstring{ L"Not Present" };
		case Windows::System::Power::BatteryStatus::Discharging:
			return hstring{ L"Dischargin" };
		case Windows::System::Power::BatteryStatus::Idle:
			return hstring{ L"Idle" };
		case Windows::System::Power::BatteryStatus::Charging:
			return hstring{ L"Charging" };
		default:
			return hstring{ L"Battery Status not supported" };
		}
	}

	FirstUWPApp01::CustomerViewModel MainPage::Model()
	{
		return m_model;
	}

	Windows::Devices::Power::Battery MainPage::Battery()
	{
		return Windows::Devices::Power::Battery::AggregateBattery();
	}

	void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
	{
		greetingOutput().Text(L"Hello, " + nameInput().Text() + L"!");
	}


	void MainPage::inputButtonVM_Click(
		winrt::Windows::Foundation::IInspectable const& sender, 
		winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		auto const foo = nameInput().Text();
		Model().Customer().Name(foo);

	}

}


