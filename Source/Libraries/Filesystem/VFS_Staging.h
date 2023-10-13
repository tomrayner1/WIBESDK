#pragma once

#include <unzip.h>
#include <iostream>
#include <Assert.h>

//#ifdef IsWin()
//#	include <windows.h>
//#	include <bcrypt.h>
//#endif

/*
	This namespace should be used for testing purposes only !

	Code should be removed and not used in production.
	// Staying for demonstration/example purposes
*/
namespace FS_StagingOnly {
	
	// print all files in test.zip 
	void dbgTryReadDebugFile()
	{
		#ifndef _DEBUG
		return;
		#endif

		unzFile zipf = unzOpen("test.wibe");

		// BAD !
		brAssert(zipf != NULL, "unzOpen() failed : Invalid path provided?");

		int result = unzGoToFirstFile(zipf);

		while (result == UNZ_OK)
		{
			char fileEntryName[256];
			unz_file_info fileinfo;

			if (unzGetCurrentFileInfo(zipf, &fileinfo, fileEntryName, sizeof(fileEntryName), NULL, 0, NULL, 0) == UNZ_OK)
			{
				std::cout << "Found: " << fileEntryName << "\n";
			}

			result = unzGoToNextFile(zipf);
		}

		// Cleanup
		unzCloseCurrentFile(zipf);
		unzClose(zipf);
	}


}

