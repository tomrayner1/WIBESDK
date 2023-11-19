#include "Core/StdAfx.h"

#include "RuntimeWindow.h"

#include "Events/EventDispatcher.h"
#include "Events/WindowEvents.h"

#include "Core/Engine.h"

namespace RW {

	RuntimeWindow::RuntimeWindow(WindowProperties& props)
		: m_Props(props)
	{

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		m_Window = glfwCreateWindow(m_Props.Width, m_Props.Height, m_Props.Title.c_str(), NULL, NULL);

		if (!m_Window)
		{
			m_ErrorDuringCreation = true;
			return;
		}

		// Point to properties
		glfwSetWindowUserPointer(m_Window, &m_Props);

		// Callbacks

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowProperties& props = *(WindowProperties*)glfwGetWindowUserPointer(window);

				props.Width = width;
				props.Height = height;

				WindowResizedEvent e = WindowResizedEvent(width, height);

				DispatchEvent(e);
			}
		);

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowClosedEvent e = WindowClosedEvent();

				DispatchEvent(e);

				g_pApp->Quit();
			}
		);

		SetVSync(true);
	}

	RuntimeWindow::~RuntimeWindow()
	{
		if (!m_ErrorDuringCreation)
		{
			glfwDestroyWindow(m_Window);
		}
	}

	void RuntimeWindow::Update()
	{
		glfwPollEvents();
	}

	void RuntimeWindow::SetVSync(bool vsync)
	{
		if (vsync)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_VSync = vsync;
	}

	WindowProperties& RuntimeWindow::GetProps()
	{
		return m_Props;
	}

}