#include "Core/StdAfx.h"

#include "Engine.h"

#include <DetectPlatform.h>
#include <Assert.h>

#include <VFS_Staging.h>

// Hide the command prompt pop-up in release mode
#if IsWin()
# 	ifndef _DEBUG
#		pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#	endif
#endif

void SmallCleanup();

int main(int argc, char* argv)
{
	#if 1 // Testing 
	FS_StagingOnly::dbgTryReadDebugFile();
	return 0;
	#endif
	g_pApp = Engine::GetApplication();

	if (brAssert(g_pApp != nullptr, "Engine::GetApplication() is not defined!"))
	{
		logger->Error("Engine::GetApplication() is nullptr, define in client !");

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