#include "Core/StdAfx.h"

#include "EventDispatcher.h"
#include "Core/Engine.h"

namespace wibe {

	void DispatchEvent(Event& e)
	{
		#ifndef SHIPPING
		logger->Info("[Event] " + e.ToString() + " dispatched.");
		#endif

		g_EventQueue.push(&e);
	}

}