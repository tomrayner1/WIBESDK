#pragma once

#include <string>
#include <queue>

// fwd declaration
class Engine::Event;

namespace RWEngine {

	// Lets make a queue system instead of having a current event that must 
	// be handled instantly.
	inline std::queue<Engine::Event*> g_EventQueue;

}

namespace Engine {

	class Event 
	{
	public:

		virtual const char* GetName() = 0;

		virtual std::string ToString() const;

		bool IsHandled();
		void SetHandled(bool val);

	private:
		bool m_Handled = false;
	};

}