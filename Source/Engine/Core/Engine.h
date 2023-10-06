#pragma once

#include "Logger.h"
#include "Application/BaseApplication.h"

inline Logger* logger = new Logger();

inline RWEngine::BaseApplication* g_pApp; // defined in entry point

// RWEngine namespace for internal use,
// Engine namespace for external use!

namespace RWEngine {
}

#include "Application/BaseApplication.h"

namespace Engine {

	extern RWEngine::BaseApplication* GetApplication();

}