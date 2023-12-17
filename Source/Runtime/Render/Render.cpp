#include "Core/StdAfx.h"

#include "Render.h"

namespace wibe {

	RenderAPI PickAppropriateRenderAPI()
	{
#if defined(_WIN32) || defined(_WIN64) // Target DirectX on windows
		return RenderAPI::DIRECTX12;
#else
		return RenderAPI::VULKAN; // Fallback to vulkan, its mostly cross-platform anyway
#endif
	}

	void SetupRenderGlobalVars()
	{
		if (g_RenderAPI == RenderAPI::NONE)
		{
			g_RenderAPI = PickAppropriateRenderAPI();
		}
	}

}