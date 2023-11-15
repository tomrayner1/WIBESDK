#pragma once

#include "Layers/Layer.h"
#include "Events/Event.h"

namespace RW {

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