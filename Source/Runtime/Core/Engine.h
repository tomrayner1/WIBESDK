#pragma once

#include "Logger.h"
#include "Application/BaseApplication.h"

inline RW::Logger* logger = new RW::Logger();

inline RW::BaseApplication* g_pApp = nullptr; // defined in entry point

namespace RW { namespace Internal_Only {

	void StartCore();
	void StopCore();

}

	extern BaseApplication* GetApplication();

	inline bool g_ShouldRestartProgram = true;

}