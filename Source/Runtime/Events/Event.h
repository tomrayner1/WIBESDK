#pragma once

#include <string>
#include <queue>

// fwd declaration
namespace wibe {
	class Event;

	struct EventType;
}


namespace wibe {

	// Lets make a queue system instead of having a current event that must 
	// be handled instantly.
	inline std::queue<Event*> g_EventQueue;

}

namespace wibe {

	struct EventType
	{
		std::string		Name;
		std::string Category;
	};

	class Event 
	{
	public:
		Event(EventType type);

		EventType GetType() const;

		std::string ToString() const;

		inline bool InCategory(std::string categoryName);

		bool IsHandled();
	protected:
		bool m_Handled = false;
		EventType m_EventType;
	};

}