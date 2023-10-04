#pragma once

#include <string>
#include <chrono>

class ScopeTimer
{
public:
	ScopeTimer(std::string identifier);
	~ScopeTimer();

	float CurrentTime();
	std::string CurrentTimeFormatted();
private:
	std::string m_Id;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_Timestamp;
};

