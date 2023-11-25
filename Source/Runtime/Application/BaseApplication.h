#pragma once

#include "ApplicationProperties.h"
#include "Layers/Layer.h"
#include "Layers/LayerStack.h"
#include "Window/RuntimeWindow.h"

#include <memory>

namespace wibe {

	class BaseApplication
	{
	public:
		BaseApplication(const ApplicationProperties& props);
		virtual ~BaseApplication();

		void Run();
		void Quit();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		void OnEvent(Event& event);

		const ApplicationProperties& GetProps() const;
	private:
		ApplicationProperties m_Props;
		bool m_Running;
		LayerStack m_LayerStack;
		std::unique_ptr<RuntimeWindow> m_RuntimeWindow;
	protected:
		std::string m_DiscordClientToken = "";
	};

}
