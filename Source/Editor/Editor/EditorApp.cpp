#include "EditorApp.h"

#include "EditorLayer.h"

//
// Entry point
//
RW::BaseApplication* RW::GetApplication()
{
	RW::ApplicationRequirements req = RW::ApplicationRequirements{};

	req.FileSystem = true;
	req.DiscordRPC = true;

	RW::ApplicationProperties props = {
		"Editor",
		req
	};

	return new EditorApp(props);
}

//
// Constructor
//
EditorApp::EditorApp(const RW::ApplicationProperties& props)
	: RW::BaseApplication(props), m_EditorLayer(EditorLayer())
{
	m_DiscordClientToken = 1175921210127831120;
	PushLayer(&m_EditorLayer);
}

EditorApp::~EditorApp()
{
}
