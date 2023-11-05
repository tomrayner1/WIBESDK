#pragma once

#include "ApplicationProperties.h"

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

		const Engine::ApplicationProperties& GetProps() const;
	private:
		Engine::ApplicationProperties m_Props;
		bool m_Running;

		std::unique_ptr<RuntimeWindow> m_RuntimeWindow;
	};

}
