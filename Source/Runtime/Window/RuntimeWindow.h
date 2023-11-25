#pragma once

#include <string>
#include <GLFW/glfw3.h>

namespace wibe {

	struct WindowProperties
	{
		std::string Title = "Wibe Engine";
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

		void Update();

		void SetVSync(bool vsync);

		WindowProperties& GetProps();
	private:
		WindowProperties& m_Props;
		GLFWwindow* m_Window;

		bool m_ErrorDuringCreation = false;

		bool m_VSync = true;
		WindowDisplayType m_WindowDisplayType = WINDOWED;
	};

}