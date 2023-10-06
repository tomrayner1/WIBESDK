#include "StdAfx.h"

#include "Logger.h"

//
// Constructor
//
Logger::Logger()
	: m_CurrentLevel(LogLevel::INFO)
	, m_CurrentPrefix("")
	, m_LoggingStatistics(LogStatistics{})
{
	#if 0
	info("Logger - Done.");
	#endif
}

// 
// Destructor
//
Logger::~Logger()
{
	ResetPrefix();
	SetLevel(LogLevel::INFO);

	Msg("\nLogging statistics for this session: ");

	Msg("  Info: " + std::to_string(--m_LoggingStatistics.InfoCount));
	Msg("  Warning: " + std::to_string(m_LoggingStatistics.WarnCount));
	Msg("  Error: " + std::to_string(m_LoggingStatistics.ErrorCount));
	Msg("  Critical: " + std::to_string(m_LoggingStatistics.CriticalCount));

	#ifdef _DEBUG
	Msg("  Debug: " + std::to_string(m_LoggingStatistics.DebugCount));
	#endif
}

//
// Methods
//
void Logger::Info(std::string msg)
{
	m_LoggingStatistics.InfoCount++;

	printf("%s%s\n", GetPrefix().c_str(), msg.c_str());
}

void Logger::Warn(std::string msg)
{
	m_LoggingStatistics.WarnCount++;

	printf("! %s%s\n", GetPrefix().c_str(), msg.c_str());
}

void Logger::Error(std::string msg)
{
	m_LoggingStatistics.ErrorCount++;

	printf("!! %s%s\n", GetPrefix().c_str(), msg.c_str());
}

void Logger::Critical(std::string msg)
{
	m_LoggingStatistics.CriticalCount++;

	printf("\n===== [CRITICAL] \n%s%s\n\n", GetPrefix().c_str(), msg.c_str());
}

void Logger::Debug(std::string msg)
{
	#ifdef _DEBUG
	m_LoggingStatistics.DebugCount++;

	printf("[DEBUG] %s%s\n", GetPrefix().c_str(), msg.c_str());
	#endif
}

void Logger::Msg(std::string msg)
{
	switch (m_CurrentLevel)
	{
	case LogLevel::INFO:
		Info(msg);
		break;
	case LogLevel::WARN:
		Warn(msg);
		break;
	case LogLevel::ERROR:
		Error(msg);
		break;
	case LogLevel::CRITICAL:
		Critical(msg);
		break;
	}
}

void Logger::ResetPrefix()
{
	m_CurrentPrefix = "";
}

//
// Getters
//
std::string Logger::GetPrefix()
{
	if (m_CurrentPrefix == "")
	{
		return "";
	}
	else
	{
		return "[" + m_CurrentPrefix + "] ";
	}
}

//
// Setters
//
void Logger::SetLevel(LogLevel level)
{
	m_CurrentLevel = level;
}

void Logger::SetPrefix(std::string prefix)
{
	m_CurrentPrefix = prefix;
}