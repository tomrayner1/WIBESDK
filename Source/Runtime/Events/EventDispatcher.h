#pragma once

#include "Event.h"

#include <functional>

namespace Engine {

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event);

		template<typename T>
		bool Dispatch(EventFunc<T> func);

	private:
		Event& m_Event;
	};

}