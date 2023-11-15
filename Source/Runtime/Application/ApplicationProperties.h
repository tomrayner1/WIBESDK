#pragma once

#include <string>

#include "ApplicationRequirements.h"

namespace RW {

	struct ApplicationProperties
	{
		std::string Name;
		ApplicationRequirements& Requirements;
	};

}
