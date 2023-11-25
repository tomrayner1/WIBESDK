#include "Core/StdAfx.h"

#include "LayerStack.h"

namespace wibe {

	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			layer->OnDetatch();
		}

		m_Layers.erase(begin(), end());
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto target = std::find(m_Layers.begin(), m_Layers.end(), layer);

		if (target != m_Layers.end())
		{
			m_Layers.erase(target);
			m_LayerInsert--;
		}
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto target = std::find(m_Layers.begin(), m_Layers.end(), overlay);

		if (target != m_Layers.end())
		{
			m_Layers.erase(target);
		}
	}

	std::vector<Layer*>::iterator LayerStack::begin()
	{
		return m_Layers.begin();
	}

	std::vector<Layer*>::iterator LayerStack::end()
	{
		return m_Layers.end();
	}

}