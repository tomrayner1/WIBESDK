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
		"%{Includes.GLFW}",
		"%{Includes.imgui}",
		"%{Includes.yaml}"
	}

	links {
		"BaseLibrary",
		"FileSystem",
		"%{Libraries.GLFW}"
	}

	defines {
		"GLFW_INCLUDE_NONE",
		"YAML_CPP_STATIC_DEFINE"
	}

	filter "configurations:Debug"
		links {
			"%{Libraries.yaml_d}"
		}
	
	filter "configurations:not Debug"
		links {
			"%{Libraries.yaml}"
		}
	
	filter ""

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

		"%{SourceFolder}/Editor/resource.rc",
		"%{SourceFolder}/Editor/**.ico"
	}

	includedirs {
		"%{SourceFolder}/Editor/",
		"%{Includes.BaseLibrary}",
		"%{Includes.FileSystem}",
		"%{Includes.Runtime}",
		"%{Includes.GLFW}",
		"%{Includes.yaml}"
	}

	links {
		"BaseLibrary",
		"FileSystem",
		"Runtime"
	}

group ""