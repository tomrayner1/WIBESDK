group "Engine"

project "Runtime"
	location "%{SourceFolder}/Runtime/"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	files {
		"%{SourceFolder}/Runtime/**.h",
		"%{SourceFolder}/Runtime/**.cpp"
	}

	includedirs {
		"%{SourceFolder}/Runtime/",
		"%{Includes.BaseLibrary}",
		"%{Includes.FileSystem}",
		"%{Includes.minizip}",
		"%{Includes.zlib}"
	}

	links {
		"BaseLibrary",
		"FileSystem"
	}

Includes["Runtime"] = "%{SourceFolder}/Runtime/"

project "Editor"
	location "%{SourceFolder}/Editor/"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	files {
		"%{SourceFolder}/Editor/**.h",
		"%{SourceFolder}/Editor/**.cpp",
		"%{SourceFolder}/Editor/Editor.rc"
	}

	includedirs {
		"%{SourceFolder}/Editor/",
		"%{Includes.BaseLibrary}",
		"%{Includes.FileSystem}",
		"%{Includes.Runtime}"
	}

	links {
		"BaseLibrary",
		"FileSystem",
		"Runtime"
	}

	addResource("Editor")

group ""