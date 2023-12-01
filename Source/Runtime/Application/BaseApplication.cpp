#include "Core/StdAfx.h"

#include "BaseApplication.h"
#include "ApplicationProperties.h"
#include "Layers/Layer.h"
#include "Core/Engine.h"

#include "Render/Render.h"

namespace wibe {

	BaseApplication::BaseApplication(const ApplicationProperties& props, RenderAPI preferredAPI=RenderAPI::NONE)
		: m_Running(true), m_Props(props)
	{
		g_RenderAPI = preferredAPI;

		SetupRenderGlobalVars(); // will set the render api to the most appropriate for the target platform

		WindowProperties wndProps = {};
		wndProps.Title = props.Name;

		m_RuntimeWindow = std::unique_ptr<RuntimeWindow>(new RuntimeWindow(wndProps));
	}

	BaseApplication::~BaseApplication()
	{
	}

	void BaseApplication::Run()
	{
		//StagingOnly::OutputVars();

		uint64_t frameCount = 1;

		while (m_Running)
		{
			while (!g_EventQueue.empty())
			{
				Event* event = g_EventQueue.front();

				OnEvent(*event);

				g_EventQueue.pop();
			}

			for (Layer* layer : m_LayerStack)
			{
				layer->OnFrame();
			}
			
			m_RuntimeWindow->Update();

			//logger->Info("[Application] Frame " + std::to_string(frameCount));

			frameCount++;
		}
	}

	void BaseApplication::Quit()
	{
		m_Running = false;
	}

	void BaseApplication::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void BaseApplication::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void BaseApplication::OnEvent(Event& event)
	{
		for (auto layer = m_LayerStack.end(); layer != m_LayerStack.begin();)
		{
			(*--layer)->OnEvent(event);

			if (event.IsHandled())
			{
				break;
			}
		}
	}

	RenderAPI BaseApplication::GetPreferredRenderingAPI()
	{
		return g_RenderAPI;
	}

	const ApplicationProperties& BaseApplication::GetProps() const
	{
		return m_Props;
	}

}
