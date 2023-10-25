#include "Core/StdAfx.h"
#include "BaseApplication.h"

namespace RWEngine {

	BaseApplication::BaseApplication()
		: m_Running(true)
	{

	}

	BaseApplication::~BaseApplication()
	{

	}

	void BaseApplication::Quit()
	{
		m_Running = false;
	}

}
