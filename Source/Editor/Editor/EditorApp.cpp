#include "EditorApp.h"

#include "EditorLayer.h"

#include <Render/Render.h>

//
// Entry point
//
wibe::BaseApplication* wibe::GetApplication()
{
	wibe::ApplicationRequirements req = wibe::ApplicationRequirements{};

	req.FileSystem = true;

	wibe::ApplicationProperties props = {
		"Wibe Editor",
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
	PushLayer(&m_EditorLayer);
}

EditorApp::~EditorApp()
{
}
