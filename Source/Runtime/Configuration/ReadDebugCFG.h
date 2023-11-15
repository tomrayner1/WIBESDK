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
			logger->Warn("Config/debug.cfg does not exist!");
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
			logger->Warn("YAML ERROR: " + std::string(e.what()));
		}
	}

}
