#pragma once

#include "Event.h"

namespace wibe {

	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent()
			: Event({ "WindowClosed", "Window" })
		{
		}
	};

	class WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(uint16_t width, uint16_t height)
			: Event({ "WindowResized", "Window" })
			, m_Width(width), m_Height(height)
		{
		}
	private:
		uint16_t m_Width, m_Height;
	};

}