#include "Core/StdAfx.h"

#include "DiscordIntegration.h"

#include <filesystem>

namespace wibe { namespace DiscordI {


	void Setup(std::string token)
	{
		logger->Info("wibe::DiscordI::Setup()");
		DiscordEventHandlers handlers;
		Discord_Initialize(token.c_str(), &handlers, 1, NULL);
	}

	void Tick()
	{
		DiscordRichPresence discordPresence{};
		discordPresence.state = "State";
		discordPresence.details = "details";
		discordPresence.startTimestamp = g_StartTime;
		discordPresence.endTimestamp = time(0) + 5 * 60;
		discordPresence.largeImageKey = "canary-large";
		discordPresence.smallImageKey = "ptb-small";
		discordPresence.partyId = "party1234";
		discordPresence.partySize = 1;
		discordPresence.partyMax = 6;
		discordPresence.matchSecret = "xyzzy";
		discordPresence.joinSecret = "join";
		discordPresence.spectateSecret = "look";
		discordPresence.instance = 0;

		Discord_UpdatePresence(&discordPresence);
		Discord_RunCallbacks();

		logger->Info("wibe::DiscordI::Tick()");
	}

	void Shutdown()
	{
		Discord_Shutdown();

		logger->Info("wibe::DiscordI::Shutdown()");
	}

}}