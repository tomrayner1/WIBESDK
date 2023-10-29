#pragma once

#include "Event.h"

namespace Engine {

	class MouseButtonDownEvent : public Event
	{
	public:
		MouseButtonDownEvent(float xoffset, float yoffset, int key)
			: m_XOffset(xoffset), m_YOffset(yoffset), m_KeyID(key)
		{
		}

		virtual EventType GetType() const override
		{
			return
			{
				"MouseButtonDown", "Mouse"
			};
		}

		inline float GetX() const
		{
			return m_XOffset;
		}

		inline float GetY() const
		{
			return m_YOffset;
		}

		inline int GetKeyID() const
		{
			return m_KeyID;
		}
	private:
		float m_XOffset, m_YOffset;

		int m_KeyID;
	};

	class MouseButtonUpEvent : public Event
	{
	public:
		MouseButtonUpEvent(float xoffset, float yoffset, int key)
			: m_XOffset(xoffset), m_YOffset(yoffset), m_KeyID(key)
		{
		}

		virtual EventType GetType() const override
		{
			return
			{
				"MouseButtonUp", "Mouse"
			};
		}

		inline float GetX() const
		{
			return m_XOffset;
		}

		inline float GetY() const
		{
			return m_YOffset;
		}

		inline int GetKeyID() const
		{
			return m_KeyID;
		}
	private:
		float m_XOffset, m_YOffset;

		int m_KeyID;
	};

	// Might need to be re-written at some point,
	// idk if storing the scroll direction as only up is a good idea
	// however 1 bit seems like enough.
	class MouseScrollEvent : public Event 
	{
	public:
		MouseScrollEvent(float xoffset, float yoffset, bool up)
			: m_XOffset(xoffset), m_YOffset(yoffset), m_ScrollUp(up)
		{
		}

		virtual EventType GetType() const override
		{
			return
			{
				"MouseScroll", "Mouse"
			};
		}

		inline float GetX() const
		{
			return m_XOffset;
		}

		inline float GetY() const
		{
			return m_YOffset;
		}

		inline bool IsScrollingUp() const
		{
			return m_ScrollUp;
		}
	private:
		float m_XOffset, m_YOffset;

		bool m_ScrollUp;
	};

	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float xoffset, float yoffset)
			: m_XOffset(xoffset), m_YOffset(yoffset)
		{
		}

		virtual EventType GetType() const override
		{
			return
			{
				"MouseMove", "Mouse"
			};
		}

		inline float GetX() const
		{
			return m_XOffset;
		}

		inline float GetY() const
		{
			return m_YOffset;
		}
	private:
		float m_XOffset, m_YOffset;
	};

}