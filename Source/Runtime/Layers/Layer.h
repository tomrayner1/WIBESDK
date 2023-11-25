#pragma once

#include <string>

#include "Events/Event.h"

namespace wibe {

	class Layer
	{
	public:
		#ifdef _DEBUG
		Layer(const std::string& name = "Layer");
		#endif
		Layer();
		
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetatch() {}

		virtual void OnFrame() {}

		virtual void OnEvent(Event& event) {}
		
		#ifdef _DEBUG
		inline const std::string& GetName() const;
	private:
		std::string m_Name;
		#endif
	private:
		bool m_Enabled; 
	};

}