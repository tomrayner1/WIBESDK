#include "Core/StdAfx.h"

#include "Layer.h"

namespace Engine {

	#ifdef _DEBUG

	Layer::Layer(const std::string& name)
		: m_Name(name), m_Enabled(true)
	{
	}

	inline const std::string& Layer::GetName() const
	{
		return m_Name;
	}

	#endif

	Layer::Layer()
		: m_Enabled(true)
	{
	}

	Layer::~Layer()
	{
	}

}