#include "Core/StdAfx.h"

#include "LayerStack.h"

namespace Runtime {

	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Engine::Layer* layer : m_Layers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Engine::Layer* layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	void LayerStack::PopLayer(Engine::Layer* layer)
	{
		auto target = std::find(m_Layers.begin(), m_Layers.end(), layer);

		if (target != m_Layers.end())
		{
			m_Layers.erase(target);
			m_LayerInsert--;
		}
	}

	void LayerStack::PushOverlay(Engine::Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopOverlay(Engine::Layer* overlay)
	{
		auto target = std::find(m_Layers.begin(), m_Layers.end(), overlay);

		if (target != m_Layers.end())
		{
			m_Layers.erase(target);
		}
	}

	std::vector<Engine::Layer*>::iterator LayerStack::begin()
	{
		return m_Layers.begin();
	}

	std::vector<Engine::Layer*>::iterator LayerStack::end()
	{
		return m_Layers.end();
	}

}