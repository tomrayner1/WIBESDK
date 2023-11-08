#include "Core/StdAfx.h"

#include "Layer.h"

namespace Runtime {

	#ifdef _DEBUG

	Layer::Layer(const std::string& name)
		: m_Name(name), m_Enabled(true)
	{
	}

	#else

	Layer::Layer()
		: m_Enabled(true)
	{
	}

	#endif

	Layer::~Layer()
	{
	}

}