#include "ScopeTimer.h"

#include <iostream>

float calculateCurrentTime(std::chrono::time_point<std::chrono::high_resolution_clock> start)
{
	auto finish = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = finish - start;

	float timeTaken = duration.count() * 1000.0f;

	return timeTaken;
}

ScopeTimer::ScopeTimer(std::string identifier)
	: m_Id(identifier), 
	m_Timestamp(std::chrono::high_resolution_clock::now())
{
}

ScopeTimer::~ScopeTimer()
{
	float timeTaken = calculateCurrentTime(m_Timestamp);

	if (m_Id == "")
	{
		std::cout << "Task took " << timeTaken << "ms.\n";
	}
	else
	{
		std::cout << "'" << m_Id << "' took " << timeTaken << "ms.\n";
	}
}

float ScopeTimer::CurrentTime()
{
	return calculateCurrentTime(m_Timestamp);
}

std::string ScopeTimer::CurrentTimeFormatted()
{
	return std::string(std::format("{}", CurrentTime()));
}
