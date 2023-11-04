#pragma once

#include <string>
#include <GLFW/glfw3.h>

namespace Engine {

	struct WindowProperties
	{
		std::string Title = "RW Engine";
		uint16_t Width = 1280;
		uint16_t Height = 720;
	};

	enum WindowDisplayType
	{
		WINDOWED = 0,
		FULLSCREEN,
		FULLSCREEN_BORDERLESS
	};

	class RuntimeWindow
	{
	public:
		RuntimeWindow(WindowProperties& props);
		~RuntimeWindow();
	private:
		WindowProperties& m_Props;
		GLFWwindow* m_Window;

		bool m_ErrorDuringCreation = false;

		bool m_Vsync = false;
		WindowDisplayType m_WindowDisplayType = WINDOWED;
	};

}