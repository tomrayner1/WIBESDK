#pragma once

#include "ApplicationRequirements.h"

namespace Engine {

	class BaseApplication
	{
	public:
		BaseApplication();
		virtual ~BaseApplication();

		void Quit();
	public:
		Engine::ApplicationRequirements m_Requirements;

	private:
		bool m_Running;
	};

}
