ThirdPartyDir = "%{wks.location}/Source/ThirdParty"

Includes = {}
Libraries = {}

--[[
	bzip2
]]

Libraries["bzip2"] = "%{ThirdPartyDir}/bzip2/bzip2.lib"

--[[
	discord_rpc
]]

Includes["discord_rpc"] = "%{ThirdPartyDir}/discord_rpc/include/"
Libraries["discord_rpc"] = "%{ThirdPartyDir}/discord_rpc/discord-rpc.lib" 

--[[
	GLFW
]]

Includes["GLFW"] = "%{ThirdPartyDir}/GLFW/include/"
Libraries["GLFW"] = "%{ThirdPartyDir}/GLFW/glfw3.lib"

--[[
	imgui
]]

Includes["imgui"] = "%{ThirdPartyDir}/imgui/include/"

--[[
	liblzma
]]

Libraries["liblzma"] = "%{ThirdPartyDir}/liblzma/liblzma.lib"

--[[
	minizip
]]

Includes["minizip"] = "%{ThirdPartyDir}/minizip/include/"
Libraries["minizip"] = "%{ThirdPartyDir}/minizip/libminizip.lib"

--[[
	yaml-cpp
]]

Includes["yaml"] = "%{ThirdPartyDir}/yaml-cpp/include/"
Libraries["yaml"] = "%{ThirdPartyDir}/yaml-cpp/yaml-cpp.lib"
Libraries["yaml_d"] = "%{ThirdPartyDir}/yaml-cpp/yaml-cppd.lib"

--[[
	zlib
]]

Includes["zlib"] = "%{ThirdPartyDir}/zlib/include/"
Libraries["zlib"] = "%{ThirdPartyDir}/zlib/zlibstatic.lib"

--[[
	zstd
]]

Libraries["zstd"] = "%{ThirdPartyDir}/zstd/zstd_static.lib"

--
-- Platform specific
--

--[[
	Windows
]]

Libraries["BCrypt"] = "Bcrypt.lib"
