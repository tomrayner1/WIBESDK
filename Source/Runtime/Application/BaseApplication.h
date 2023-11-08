#pragma once

#include "ApplicationProperties.h"
#include "Layers/Layer.h"
#include "Layers/LayerStack.h"
#include "Window/RuntimeWindow.h"

#include <memory>

namespace Engine {

	class BaseApplication
	{
	public:
		BaseApplication(const Engine::ApplicationProperties& props);
		virtual ~BaseApplication();

		void Run();
		void Quit();

		void PushLayer(Runtime::Layer* layer);
		void PushOverlay(Runtime::Layer* overlay);

		const Engine::ApplicationProperties& GetProps() const;
	private:
		Engine::ApplicationProperties m_Props;
		bool m_Running;
		Runtime::LayerStack m_LayerStack;
		std::unique_ptr<RuntimeWindow> m_RuntimeWindow;
	};

}
