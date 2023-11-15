#pragma once

#include "Logger.h"
#include "Application/BaseApplication.h"

inline RW::Logger* logger = new RW::Logger();

inline RW::BaseApplication* g_pApp = nullptr; // defined in entry point

namespace RW {

	void StartCore();
	void StopCore();

}

#include "Application/BaseApplication.h"

namespace RW {

	extern BaseApplication* GetApplication();

	inline bool g_ShouldRestartProgram = true;

}