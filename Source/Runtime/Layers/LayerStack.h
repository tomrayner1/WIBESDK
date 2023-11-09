#pragma once

#include "Layer.h"

#include <vector>

namespace Runtime {

	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Engine::Layer* layer);
		void PopLayer(Engine::Layer* layer);

		void PushOverlay(Engine::Layer* overlay);
		void PopOverlay(Engine::Layer* overlay);

		std::vector<Engine::Layer*>::iterator begin();
		std::vector<Engine::Layer*>::iterator end();
	private:
		std::vector<Engine::Layer*> m_Layers;
		std::vector<Engine::Layer*>::iterator m_LayerInsert;
	};

}
