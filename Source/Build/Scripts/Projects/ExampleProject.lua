group "ExampleProject"

project "Sandbox"
	location "../../../../ExampleProject/Source/Game/"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	files {
		"../../../../ExampleProject/Source/Game/**.h",
		"../../../../ExampleProject/Source/Game/**.cpp",
		"../../../../ExampleProject/Source/Game/Sandbox.rc"
	}

	includedirs {
		"../../../../ExampleProject/Source/Game/",
		"../%{Includes.BaseLibrary}",
		"../%{Includes.FileSystem}",
		"../%{Includes.Runtime}"
	}

	links {
		"BaseLibrary",
		"FileSystem",
		"Runtime"
	}

	addResource("Sandbox")

group ""