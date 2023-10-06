#include "Core/StdAfx.h"

#include "Engine.h"

#include <DetectPlatform.h>

// Hide the command prompt pop-up in release mode
#if IsWin()
# 	ifndef _DEBUG
#		pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#	endif
#endif

void SmallCleanup();

int main(int argc, char* argv)
{
	g_pApp = Engine::GetApplication();

	if (g_pApp == nullptr)
	{
		logger->Critical("Engine::GetApplication() returned nullptr, define in client !");

		SmallCleanup();
		return 0;
	}

	SmallCleanup();
	return 0;
}

//
// Must happen before the program closes!
// Purpose: Free parts of memory that are allocated before closing.
//
void SmallCleanup()
{
	if (g_pApp != nullptr)
	{
		delete g_pApp;
	}
	
	delete logger;
}