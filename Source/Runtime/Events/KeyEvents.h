#pragma once

#include "Event.h"

namespace Engine {

	class KeyDownEvent : public Event
	{
	public:
		KeyDownEvent(int key) 
			: m_KeyID(key)
		{
		}

		virtual EventType GetType() const override
		{
			return 
			{
				"KeyDown", "Key"
			};
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
			: m_KeyID(key)
		{
		}

		virtual EventType GetType() const override
		{
			return
			{
				"KeyUp", "Key"
			};
		}

		inline int GetKeyID() const
		{
			return m_KeyID;
		}

	private:
		int m_KeyID;
	};

}
