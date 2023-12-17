#pragma once

namespace wibe {

	enum class RenderAPI
	{
		NONE,

		// win & xbox
		DIRECTX12,
		DIRECTX11,
		
		// cross platform
		VULKAN,

		// apple
		METAL,

		// debug purposes only
		OPENGL
	};

	RenderAPI PickAppropriateRenderAPI();

	void SetupRenderGlobalVars();

	inline RenderAPI g_RenderAPI = RenderAPI::NONE;
}
