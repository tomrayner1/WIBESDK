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
	Engine::ApplicationRequirements requirements = Engine::ApplicationRequirements{};

	requirements.FileSystem = true;

	this->m_Requirements = requirements;
}

EditorApp::~EditorApp()
{
}