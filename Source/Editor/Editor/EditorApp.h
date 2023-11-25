#pragma once

#include <Core/Engine.h>
#include <Application/BaseApplication.h>

#include "EditorLayer.h"

class EditorApp : public wibe::BaseApplication
{
public:
	EditorApp(const wibe::ApplicationProperties& props);
	~EditorApp();

private:
	EditorLayer m_EditorLayer;
};

