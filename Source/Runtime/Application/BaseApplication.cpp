#include "Core/StdAfx.h"
#include "BaseApplication.h"
#include "ApplicationProperties.h"
#include "Layers/Layer.h"

#if 0
#include "Configuration/ReadDebugCFG.h"
#endif

namespace RW {

	BaseApplication::BaseApplication(const ApplicationProperties& props)
		: m_Running(true), m_Props(props)
	{
		WindowProperties wndProps = {};
		wndProps.Title = props.Name;

		m_RuntimeWindow = std::unique_ptr<RuntimeWindow>(new RuntimeWindow(wndProps));
	}

	BaseApplication::~BaseApplication()
	{
		Quit();
	}

	void BaseApplication::Run()
	{
		//StagingOnly::OutputVars();

		while (m_Running)
		{
			while (!g_EventQueue.empty())
			{
				Event* event = g_EventQueue.front();

				//OnEvent(&(Event)event);
			}

			for (Layer* layer : m_LayerStack)
			{
				layer->OnFrame();
			}
			
			m_RuntimeWindow->Update();
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

	const ApplicationProperties& BaseApplication::GetProps() const
	{
		return m_Props;
	}

}
