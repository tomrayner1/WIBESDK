#pragma once

#include "Logger.h"
#include "Application/BaseApplication.h"

inline wibe::Logger* g_Logger = new wibe::Logger();

inline wibe::BaseApplication* g_pApp = nullptr; // defined in entry point

namespace wibe { namespace Internal_Only {

	void StartCore();
	void StopCore();

}

	extern BaseApplication* GetApplication();

	inline bool g_ShouldRestartProgram = true;

}