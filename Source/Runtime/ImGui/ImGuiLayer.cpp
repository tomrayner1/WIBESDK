#include "Core/StdAfx.h"

#include "ImGuiLayer.h"

namespace wibe {

	ImGuiLayer::ImGuiLayer()
		#ifdef _DEBUG
		: Layer("ImGuiLayer")
		#endif
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
	}

	void ImGuiLayer::OnDetatch()
	{
	}

	void ImGuiLayer::OnFrame()
	{
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
	}


}