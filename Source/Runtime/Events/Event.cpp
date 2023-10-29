#include "Core/StdAfx.h"

#include "Event.h"

namespace Engine {

	std::string Event::ToString() const
	{
		return this->GetType().Name;
	}

	bool Event::InCategory(std::string categoryName)
	{
		return this->GetType().Category == categoryName;
	}
}