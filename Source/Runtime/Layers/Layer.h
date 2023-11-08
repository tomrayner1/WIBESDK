#pragma once

#include <string>

#include "Events/Event.h"

namespace Runtime {

	class Layer
	{
	public:
		#ifdef _DEBUG
		Layer(const std::string& name = "Layer");
		#else
		Layer();
		#endif
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetatch() {}

		virtual void OnFrame() {}

		virtual void OnEvent(Engine::Event& event) {}
		
		#ifdef _DEBUG
		inline const std::string& GetName() const
		{
			return m_Name;
		}
	private:
		std::string m_Name;
		#endif
	private:
		bool m_Enabled; 
	};

}