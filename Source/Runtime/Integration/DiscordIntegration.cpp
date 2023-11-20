#include "Core/StdAfx.h"

#include "DiscordIntegration.h"

#include <filesystem>

namespace RW { namespace DiscordI {


	void Setup(uint64_t token)
	{
		logger->Info("RW::DiscordI::Setup()");
		DiscordEventHandlers handlers;
		Discord_Initialize(std::to_string(token).c_str(), &handlers, 1, NULL);
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
	}

	void Shutdown()
	{
		Discord_Shutdown();
	}

}}