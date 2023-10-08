#pragma once

namespace Engine {
	
	struct ApplicationRequirements
	{
		bool FileSystem = false;
	};

}

namespace RWEngine {

	class BaseApplication
	{
	public:
		BaseApplication(Engine::ApplicationRequirements requirements);
		virtual ~BaseApplication();

		void Quit();
	private:
		Engine::ApplicationRequirements m_Requirements;

		bool m_Running;
	};

}
