include "ThirdParty.lua"
include "Configuration.lua"

workspace "WIBESDK"
	platforms "x86_64"
	architecture "x86_64"
	location "%{SourceFolder}/../"

	startproject "Editor"

	targetname "%{prj.name}_%{cfg.buildcfg}_%{cfg.architecture}"

	configurations {
		"Debug",
		"Release",
		"Shipping"	
	}

	targetdir "%{TargetPath}"
	objdir "%{ObjectPath}"

	filter "configurations:Debug"
		defines {
			"_DEBUG"
		}
		symbols "On"
	
	filter "configurations:Release"
		defines {
			"NDEBUG"
		}
		optimize "On"

	filter "configurations:Shipping"
		defines {
			"NDEBUG",
			"SHIPPING"
		}
		optimize "On"
	
	filter {}

-- Internal
include "Libraries.lua"
include "Tools.lua"
include "Engine.lua"

-- External 
include "Projects/ExampleProject.lua"