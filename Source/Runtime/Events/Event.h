#pragma once

#include <string>
#include <queue>

// fwd declaration
namespace Engine {
	class Event;

	struct EventType;
}


namespace Runtime {

	// Lets make a queue system instead of having a current event that must 
	// be handled instantly.
	inline std::queue<Engine::Event*> g_EventQueue;

}

namespace Engine {

	struct EventType
	{
		std::string		Name;
		std::string Category;
	};

	class Event 
	{
	public:
		virtual EventType GetType() const = 0;

		virtual std::string ToString() const;

		inline bool InCategory(std::string categoryName);
	protected:
		bool m_Handled = false;
	};

}