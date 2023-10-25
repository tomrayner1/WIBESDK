#pragma once

#include "Logger.h"
#include "Application/BaseApplication.h"

inline Logger* logger = new Logger();

inline Engine::BaseApplication* g_pApp = nullptr; // defined in entry point

// RWEngine namespace for internal use,
// Engine namespace for external use!

namespace RWEngine {
}

#include "Application/BaseApplication.h"

namespace Engine {

	extern Engine::BaseApplication* GetApplication();

}