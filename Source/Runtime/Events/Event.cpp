#include "Core/StdAfx.h"

#include "Event.h"

namespace RW {

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