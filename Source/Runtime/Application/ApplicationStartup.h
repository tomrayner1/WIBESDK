#pragma once

// This header file only has one function
// might aswell throw the implementation
// in here as well.

#include "Core/Engine.h"

#include "ApplicationRequirements.h"

namespace Runtime {

	void SetupApplication()
	{
		Engine::ApplicationRequirements req = g_pApp->GetProps().Requirements;

		if (req.FileSystem)
		{
			// TODO: finish
		}

		if (req.LauncherWindow)
		{
			// Delay runtime window from opening
		}

		return;
	}

}
