#pragma once

#include <discord_rpc.h>

namespace RW { namespace DiscordI {

	inline int64_t g_StartTime = time(0);

	void Setup(uint64_t token);

	void Tick();

	void Shutdown();

}}
