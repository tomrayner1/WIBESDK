#pragma once

#include "Logger.h"
#include "Application/BaseApplication.h"

inline Runtime::Logger* logger = new Runtime::Logger();

inline Engine::BaseApplication* g_pApp = nullptr; // defined in entry point

// Runtime namespace for internal use,
// Engine namespace for external use!

namespace Runtime {

	void StartCore();
	void StopCore();

}

#include "Application/BaseApplication.h"

namespace Engine {

	extern Engine::BaseApplication* GetApplication();

	inline bool g_ShouldRestartProgram = true;

}