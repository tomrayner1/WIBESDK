#pragma once

#include "Event.h"

namespace RW {

	class KeyDownEvent : public Event
	{
	public:
		KeyDownEvent(int key) 
			: Event({"KeyDown", "Key"})
			, m_KeyID(key)
		{
		}

		inline int GetKeyID() const 
		{
			return m_KeyID;
		}

	private:
		int m_KeyID;
	};

	class KeyUpEvent : public Event
	{
	public:
		KeyUpEvent(int key)
			: Event({ "KeyUp", "Key" })
			, m_KeyID(key)
		{
		}

		inline int GetKeyID() const
		{
			return m_KeyID;
		}

	private:
		int m_KeyID;
	};

}
