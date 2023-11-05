#include "EditorApp.h"

//
// Entry point
//
Engine::BaseApplication* Engine::GetApplication()
{
	Engine::ApplicationRequirements req = Engine::ApplicationRequirements{};

	req.FileSystem = true;

	Engine::ApplicationProperties props = {
		"Editor",
		req
	};

	return new EditorApp(props);
}

//
// Constructor
//
EditorApp::EditorApp(const Engine::ApplicationProperties& props)
	: Engine::BaseApplication(props)
{
}

EditorApp::~EditorApp()
{
}
