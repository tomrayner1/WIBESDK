#pragma once

#include "Layers/Layer.h"
#include "Events/Event.h"

namespace wibe {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetatch();

		void OnFrame();
		void OnEvent(Event& event);
	private:

	};

}