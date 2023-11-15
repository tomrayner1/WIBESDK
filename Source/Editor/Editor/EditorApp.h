#pragma once

#include <Core/Engine.h>
#include <Application/BaseApplication.h>

#include "EditorLayer.h"

class EditorApp : public RW::BaseApplication
{
public:
	EditorApp(const RW::ApplicationProperties& props);
	~EditorApp();

private:
	EditorLayer m_EditorLayer;
};

