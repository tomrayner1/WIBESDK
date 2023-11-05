#include "Core/StdAfx.h"

#include "Engine.h"

#include <DetectPlatform.h>
#include <Assert.h>

//#include <VFS_Staging.h>
//#include <VFS.h>

// Hide the command prompt pop-up in release mode
#if IsWin()
# 	ifndef _DEBUG
#		pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#	endif
#endif

void SmallCleanup();

int main(int argc, char* argv)
{
	while (Engine::g_ShouldRestartProgram)
	{
		Engine::g_ShouldRestartProgram = false;

		Runtime::StartCore();
		g_pApp = Engine::GetApplication();

		if (brAssert(g_pApp != nullptr, "Engine::GetApplication() is not defined!"))
		{
			logger->Error("Engine::GetApplication() is nullptr, define in client !");
		}
		else
		{
			g_pApp->Run();
		}

		SmallCleanup();
		Runtime::StopCore();
	}

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

/*

	/////////////////////////////////////////////
	/// Staging code, remove!

	//FS_StagingOnly::dbgTryReadDebugFile();
	//std::cout << "\n\n\n";

	VFS::IndexZippedFile("test.wibe");

	std::vector<uint8_t> buffer; // vector of bytes

	VFS::Read("folder/as1.txt", buffer);

	const char* data = reinterpret_cast<const char*>(buffer.data()); // cast vector of bytes to char[]

	std::cout << "folder/as1.txt: \n" << data << "\n";
	VFS::Cleanup();

	return 0;
	/////////////////////////////////////////////

*/