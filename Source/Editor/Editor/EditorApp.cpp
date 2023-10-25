#include "EditorApp.h"

// Entry point for the editor
RWEngine::BaseApplication* Engine::GetApplication()
{
	return new EditorApp();
}

EditorApp::EditorApp()
{

}

EditorApp::~EditorApp()
{

}