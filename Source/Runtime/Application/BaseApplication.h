#pragma once

#include "ApplicationProperties.h"

namespace Engine {

	class BaseApplication
	{
	public:
		BaseApplication();
		virtual ~BaseApplication();

		void Quit();

		virtual Engine::ApplicationProperties GetProps() const = 0;
	private:
		bool m_Running;
	};

}
