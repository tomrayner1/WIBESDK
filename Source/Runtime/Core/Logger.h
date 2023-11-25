#pragma once

#include <string>

namespace wibe {

	enum LogLevel;

	struct LogStatistics {
		int InfoCount = 0;
		int WarnCount = 0;
		int ErrorCount = 0;
		int CriticalCount = 0;

		#if _DEBUG
		int DebugCount = 0;
		#endif
	};

	class Logger {
	public:
		Logger();
		~Logger();

		void SetPrefix(std::string prefix);
		void SetLevel(LogLevel level);

		void ResetPrefix();

		void Info(std::string msg);
		void Warn(std::string msg);
		void Error(std::string msg);
		void Critical(std::string msg);

		void Msg(std::string msg);
		void Debug(std::string msg);

	private: // functions
		std::string GetPrefix();

	private:
		LogLevel m_CurrentLevel;

		std::string m_CurrentPrefix;

		LogStatistics m_LoggingStatistics;
	};

	enum LogLevel {
		INFO,
		WARN,
		ERROR,
		CRITICAL
	};

}