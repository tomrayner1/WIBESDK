#include "EditorApp.h"

//
// Entry point
//
Engine::BaseApplication* Engine::GetApplication()
{
	return new EditorApp();
}

//
// Constructor
//
EditorApp::EditorApp()
{
}

EditorApp::~EditorApp()
{
}

//
// Props
//
Engine::ApplicationProperties EditorApp::GetProps() const
{
	Engine::ApplicationRequirements req = Engine::ApplicationRequirements{};
	
	req.FileSystem = true;

	Engine::ApplicationProperties props = {
		"Editor",
		req
	};
	
	return props;
}