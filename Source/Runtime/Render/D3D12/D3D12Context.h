#pragma once

#include "Render/RenderContext.h"

#include <GLFW/glfw3.h>

namespace wibe {

	class D3D12Context : public RenderContext
	{
	public:
		D3D12Context(GLFWwindow* window);
		~D3D12Context();

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_GLFWWindowHandle;
	};

}
