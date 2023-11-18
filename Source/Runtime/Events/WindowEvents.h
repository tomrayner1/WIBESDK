#pragma once

#include "Event.h"

namespace RW {

	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent()
			: Event({ "WindowClosed", "Window" })
		{
		}
	};

}