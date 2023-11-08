#include "Core/StdAfx.h"

#include "RuntimeWindow.h"

namespace Engine {

	RuntimeWindow::RuntimeWindow(WindowProperties& props)
		: m_Props(props)
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		m_Window = glfwCreateWindow(m_Props.Width, m_Props.Height, m_Props.Title.c_str(), NULL, NULL);

		if (!m_Window)
		{
			glfwTerminate();
			m_ErrorDuringCreation = true;
			return;
		}
	}

	RuntimeWindow::~RuntimeWindow()
	{
		if (!m_ErrorDuringCreation)
		{
			glfwDestroyWindow(m_Window);
			glfwTerminate();
		}
	}

	void RuntimeWindow::Update()
	{

	}

}