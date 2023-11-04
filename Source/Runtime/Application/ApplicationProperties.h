#pragma once

#include <string>

#include "ApplicationRequirements.h"

namespace Engine {

	struct ApplicationProperties
	{
		std::string Name;
		ApplicationRequirements& Requirements;
	};

}
