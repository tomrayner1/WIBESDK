#pragma once

#include "Layers/Layer.h"
#include "Events/Event.h"

namespace Runtime {

	class ImGuiLayer : public Engine::Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetatch();

		void OnFrame();
		void OnEvent(Engine::Event& event);
	private:

	};

}