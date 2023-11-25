#pragma once

#include <string>

#include "ApplicationRequirements.h"

namespace wibe {

	struct ApplicationProperties
	{
		std::string Name;
		ApplicationRequirements& Requirements;
	};

}
