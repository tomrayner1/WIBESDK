#include "Core/StdAfx.h"
#include "BaseApplication.h"
#include "ApplicationProperties.h"
#include "Layers/Layer.h"

namespace Engine {

	BaseApplication::BaseApplication(const Engine::ApplicationProperties& props)
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
		while (m_Running)
		{
			while (!Runtime::g_EventQueue.empty())
			{
				Event* event = Runtime::g_EventQueue.front();

				//OnEvent(&(Event)event);
			}

			for (Engine::Layer* layer : m_LayerStack)
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

	void BaseApplication::PushLayer(Engine::Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void BaseApplication::PushOverlay(Engine::Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
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

	const Engine::ApplicationProperties& BaseApplication::GetProps() const
	{
		return m_Props;
	}

}
