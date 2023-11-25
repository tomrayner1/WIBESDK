-- Relative to premake5.lua
SourceFolder = "../../"

--StartupProject = "Editor"

TargetPath = "%{SourceFolder}/../Bin/"

ObjectPath = "%{SourceFolder}/../Bin/%{prj.name}_%{cfg.buildcfg}_%{cfg.architecture}/"
