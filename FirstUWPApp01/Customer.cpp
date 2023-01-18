#include "pch.h"
#include "Customer.h"
#if __has_include("Customer.g.cpp")
#include "Customer.g.cpp"
#endif

namespace winrt::FirstUWPApp01::implementation
{
	Customer::Customer(hstring const& name) : m_name(name)
	{
	}
	hstring Customer::Name()
	{
		return m_name;
	}

	void Customer::Name(hstring const& name)
	{
		if (m_name != name)
		{
			m_name = name;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{L"Name"});
		}
	}

	event_token Customer::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler handler)
	{
		return m_propertyChanged.add(handler);
	}

	void Customer::PropertyChanged(event_token const& token)
	{
		m_propertyChanged.remove(token);
	}


}
