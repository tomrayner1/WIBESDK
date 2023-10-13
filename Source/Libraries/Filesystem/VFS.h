#pragma once

#include <map>
#include <string>
#include <unzip.h>

namespace VFS_Internal {

	struct FileInfo {
		unz_file_info FileInfo;
		long Offset;
	};

	inline std::map<std::string, FileInfo> g_FileMapping; 

}