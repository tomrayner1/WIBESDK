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
		BaseApplication();
		virtual ~BaseApplication();

		void Quit();
	private:
		Engine::ApplicationRequirements m_Requirements;

		bool m_Running;
	};

}
