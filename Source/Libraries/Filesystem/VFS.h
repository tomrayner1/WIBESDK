#pragma once

#include <map>
#include <string>
#include <unzip.h>
#include <vector>

namespace VFS {

	/*
		Used for adding a file to the global mapping.

		Params:
			path - relative or absolute path to the file.
	*/
	void IndexZippedFile(const char* path);

	/*
		Removes all of the mapped files.
	*/
	void Cleanup();

	bool Read(std::string internalPath, std::vector<uint8_t>& buffer);
}

namespace VFS_Internal {

	struct FileInfo {
		uint32_t FileIndexPosition;
		uint32_t UncompressedSize;
		//unz_file_info FileInfo;
		unz_file_pos Position;
	};

	inline std::map<std::string, FileInfo> g_FileMapping;

	inline std::vector<unzFile> g_IndexedFiles;
}