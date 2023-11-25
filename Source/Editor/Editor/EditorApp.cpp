#include "EditorApp.h"

#include "EditorLayer.h"

//
// Entry point
//
wibe::BaseApplication* wibe::GetApplication()
{
	wibe::ApplicationRequirements req = wibe::ApplicationRequirements{};

	req.FileSystem = true;
	req.DiscordRPC = true;

	wibe::ApplicationProperties props = {
		"Editor",
		req
	};

	return new EditorApp(props);
}

//
// Constructor
//
EditorApp::EditorApp(const wibe::ApplicationProperties& props)
	: wibe::BaseApplication(props), m_EditorLayer(EditorLayer())
{
	m_DiscordClientToken = 1175921210127831120;
	PushLayer(&m_EditorLayer);
}

EditorApp::~EditorApp()
{
}
