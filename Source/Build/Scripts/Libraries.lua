group "Engine/Libraries"

project "BaseLibrary"
	location "%{SourceFolder}/Libraries/BaseLibrary/"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	files {
		"%{SourceFolder}/Libraries/BaseLibrary/**.h",
		"%{SourceFolder}/Libraries/BaseLibrary/**.cpp"
	}

	includedirs {
		"%{SourceFolder}/Libraries/BaseLibrary/"
	}

Includes["BaseLibrary"] = "%{SourceFolder}/Libraries/BaseLibrary/"

project "FileSystem"
	location "%{SourceFolder}/Libraries/FileSystem/"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	files {
		"%{SourceFolder}/Libraries/FileSystem/**.h",
		"%{SourceFolder}/Libraries/FileSystem/**.cpp"
	}

	includedirs {
		"%{SourceFolder}/Libraries/FileSystem/",
		"%{Includes.BaseLibrary}",
		"%{Includes.minizip}",
		"%{Includes.zlib}"
	}

	links {
		"BaseLibrary",
		"%{Libraries.bzip2}",
		"%{Libraries.liblzma}",
		"%{Libraries.minizip}",
		"%{Libraries.zlib}",
		"%{Libraries.zstd}"
	}

	filter "system:windows"
		links {
			"%{Libraries.BCrypt}"
		}
	filter {}

Includes["FileSystem"] = "%{SourceFolder}/Libraries/FileSystem/"

group ""