#include "Core/StdAfx.h"
#include "BaseApplication.h"

#include "ApplicationProperties.h"

namespace Engine {

	BaseApplication::BaseApplication(const Engine::ApplicationProperties& props)
		: m_Running(true), m_Props(props)
	{
		WindowProperties wndProps = {};
		wndProps.Title = props.Name;

		m_RuntimeWindow = std::unique_ptr<RuntimeWindow>(new RuntimeWindow(wndProps));
	}

	BaseApplication::~BaseApplication()
	{
		
	}

	void BaseApplication::Run()
	{

	}

	void BaseApplication::Quit()
	{
		m_Running = false;
	}

	const Engine::ApplicationProperties& BaseApplication::GetProps() const
	{
		return m_Props;
	}

}
