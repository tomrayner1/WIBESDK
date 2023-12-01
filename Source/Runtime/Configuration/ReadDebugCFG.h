#pragma once

#include <yaml-cpp/yaml.h>
#include <iostream>
#include <filesystem>

#include "Core/Engine.h"

namespace StagingOnly {

	void OutputVars()
	{
		std::string path = "Config/debug.cfg";

		if (!std::filesystem::exists(path))
		{
			g_Logger->Warn("Config/debug.cfg does not exist!");
			return;
		}

		try 
		{
			YAML::Node config = YAML::LoadFile(path);

			int version = config["version"].as<int>();

			std::cout << "Version: " << version << "\n";
		}
		catch (const std::exception& e)
		{
			g_Logger->Warn("YAML ERROR: " + std::string(e.what()));
		}
	}

}
