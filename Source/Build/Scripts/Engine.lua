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
		"%{Includes.zlib}",
		"%{Includes.GLFW}"
	}

	links {
		"BaseLibrary",
		"FileSystem",
		"%{Libraries.GLFW}"
	}

	defines {
		"GLFW_INCLUDE_NONE"
	}

Includes["Runtime"] = "%{SourceFolder}/Runtime/"

project "Editor"
	location "%{SourceFolder}/Editor/"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	debugdir "%{TargetPath}"

	files {
		"%{SourceFolder}/Editor/**.h",
		"%{SourceFolder}/Editor/**.cpp",
		"%{SourceFolder}/Editor/Editor.rc"
	}

	includedirs {
		"%{SourceFolder}/Editor/",
		"%{Includes.BaseLibrary}",
		"%{Includes.FileSystem}",
		"%{Includes.Runtime}",
		"%{Includes.GLFW}"
	}

	links {
		"BaseLibrary",
		"FileSystem",
		"Runtime"
	}

	addResource("Editor")

group ""