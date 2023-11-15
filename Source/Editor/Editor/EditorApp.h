#pragma once

#include <Core/Engine.h>
#include <Application/BaseApplication.h>

#include "EditorLayer.h"

class EditorApp : public Engine::BaseApplication
{
public:
	EditorApp(const Engine::ApplicationProperties& props);
	~EditorApp();

private:
	EditorLayer m_EditorLayer;
};

