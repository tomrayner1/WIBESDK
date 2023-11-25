#include "Core/StdAfx.h"

#include "Event.h"

namespace wibe {

	Event::Event(EventType type)
		: m_EventType(type)
	{
	}

	EventType Event::GetType() const
	{
		return m_EventType;
	}

	std::string Event::ToString() const
	{
		return this->GetType().Name;
	}

	bool Event::InCategory(std::string categoryName)
	{
		return this->GetType().Category == categoryName;
	}

	bool Event::IsHandled()
	{
		return m_Handled;
	}
}