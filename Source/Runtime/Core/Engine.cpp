#include "Core/StdAfx.h"

#include "Engine.h"
#include <GLFW/glfw3.h>

namespace RW {

	void Internal_Only::StartCore()
	{
		glfwInit();
	}

	void Internal_Only::StopCore()
	{
		glfwTerminate();
	}

}
