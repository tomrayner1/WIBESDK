#include "Core/StdAfx.h"

#include "RuntimeWindow.h"

#include "Events/EventDispatcher.h"
#include "Events/WindowEvents.h"

#include "Core/Engine.h"

#include "Render/Render.h"
#include "Render/D3D12/D3D12Context.h"

namespace wibe {

	RuntimeWindow::RuntimeWindow(WindowProperties& props)
		: m_Props(props), m_Context(nullptr)
	{

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		m_Window = glfwCreateWindow(m_Props.Width, m_Props.Height, m_Props.Title.c_str(), NULL, NULL);

		if (!m_Window)
		{
			m_ErrorDuringCreation = true;
			return;
		}
		
		// TODO: properly implement other rendering apis
		switch (g_RenderAPI)
		{
		case RenderAPI::DIRECTX11:
			g_Logger->Info("Using DX11...");

			break;
		case RenderAPI::DIRECTX12:
			g_Logger->Info("Using DX12...");

			m_Context = new D3D12Context(m_Window);

			break;
		case RenderAPI::VULKAN:
			g_Logger->Info("Using Vulkan...");

			break;
		case RenderAPI::METAL:
			g_Logger->Info("Using Metal...");

			break;
		case RenderAPI::OPENGL:
			g_Logger->Info("Using OpenGL...");

//			m_Context = new OpenGLContext(m_Window);

			break;
		}

		if (m_Context != nullptr)
			m_Context->Init();

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