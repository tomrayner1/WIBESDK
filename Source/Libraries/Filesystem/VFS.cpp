#include "FSPCH.h"

#include "VFS.h"
#include <BaseAssert.h>

#include <iostream>

namespace VFS {

	/*
		Used for adding a file to the global mapping.

		Params:
			path - relative or absolute path to the file.
	*/
	void IndexZippedFile(const char* path)
	{
		// Loops through all of the results in a zip file,
		// filters out all of the folders and adds the files to
		// a global mapping with an offset so that it can easily
		// be loaded again.

		constexpr uint16_t MAX_ZIP_FILE_LEN = 256;

		unzFile indexZip = unzOpen(path);

		brAssert(path != NULL, "Invalid path provided to VFS::IndexZippedFile(const char*);");

		// Previous error wont be caught in release mode so we have to do this
		if (path == NULL)
		{
			return;
		}

		int result = unzGoToFirstFile(indexZip);
		long offset = 0;

		while (result == UNZ_OK)
		{
			char entryName[MAX_ZIP_FILE_LEN];
			unz_file_info fileinfo;

			if (unzGetCurrentFileInfo(indexZip, &fileinfo, entryName, sizeof(entryName), NULL, 0, NULL, 0) == UNZ_OK)
			{
				offset += fileinfo.compressed_size;

				char endChar = entryName[strlen(entryName) - 1];
				bool isFolder = endChar == '/';

				if (isFolder)
				{
					result = unzGoToNextFile(indexZip);
					continue;
				}

				unz_file_pos filePos;
				brAssert(unzGetFilePos(indexZip, &filePos) == UNZ_OK);

				VFS_Internal::FileInfo vfsInfo;
				vfsInfo.FileIndexPosition = VFS_Internal::g_IndexedFiles.size();
				vfsInfo.UncompressedSize = fileinfo.uncompressed_size;
				vfsInfo.Position = filePos;
				
				VFS_Internal::g_FileMapping[std::string(entryName)] = vfsInfo;

				std::cout << "[VFS] Cached " << entryName << "\n";
				//std::cout << entryName << " | endchar: " << endChar << " | isFolder: " << isFolder << "\n";
			}

			result = unzGoToNextFile(indexZip);
		}

		VFS_Internal::g_IndexedFiles.push_back(indexZip);
	}

	/*
		Removes all of the mapped files.
	*/
	void Cleanup()
	{
		VFS_Internal::g_FileMapping.clear();

		for (auto element : VFS_Internal::g_IndexedFiles)
		{
			unzClose(element);
		}
	}

	bool Read(std::string internalPath, std::vector<uint8_t>& buffer)
	{
		if (!VFS_Internal::g_FileMapping.contains(internalPath))
		{
			return false;
		}

		VFS_Internal::FileInfo fileInfo = VFS_Internal::g_FileMapping[internalPath];

		unzFile file = VFS_Internal::g_IndexedFiles[fileInfo.FileIndexPosition];

		if (unzGoToFilePos(file, &fileInfo.Position) != UNZ_OK)
		{
			return false;
		}

		if (unzOpenCurrentFile(file) != UNZ_OK)
		{
			return false;
		}

		buffer.resize(static_cast<size_t>(fileInfo.UncompressedSize));
		int bytesRead = unzReadCurrentFile(file, buffer.data(), static_cast<unsigned int>(buffer.size()));

		return true;
	}

}