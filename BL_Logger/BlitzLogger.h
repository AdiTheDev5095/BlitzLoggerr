#pragma once
#include <stdio.h>
#include <iostream>
#include<time.h>

using namespace std;

namespace Blitz_Logger {

	enum LogPriority {
		Trace,
		Info,
		Warn,
		Error,
		Fatal
	};
	class Logger {

	private:
		static LogPriority Priority;

		template<typename ...Args>
		static void printer(LogPriority, LogPriority, int, const char*, const char*, Args ...);

	public:
		inline static void SetPriority(LogPriority);
		template<typename ...Args>
		static void Trace(const char*, Args ...);
		template<typename ...Args>
		static void Info(const char*, Args ...);
		template<typename ...Args>
		static void Warn(const char*, Args ...);
		template<typename ...Args>
		static void Error(const char*, Args ...);
		template<typename ...Args>
		static void Fatal(const char*, Args ...);


	};
	LogPriority Logger::Priority = (LogPriority)LogPriority::Info;


	//---printer
	template<typename ...Args>
	void Logger::printer(LogPriority message_Priority,
		LogPriority GreaterPriority,
		int colourcode,
		const char* message,
		const char* messagePriorityStr,
		Args ... args) {

		//--time
		if (message_Priority <= GreaterPriority) {
			printf("\033[1;%dm[%s]%s\t", colourcode, __TIME__, messagePriorityStr);
			printf(message, args...);
			printf("\n");
			printf("\033[1;37m");
		}
	}
	inline void Logger::SetPriority(LogPriority Priority) {

		Logger::Priority = Priority;
	}

	template<typename ...Args>
	inline void Logger::Trace(const char* message, Args ... args)
	{


		//--printing
		Logger::printer(LogPriority::Trace, LogPriority::Info, 37, message, "[Trace]", args...);

	}

	template<typename ...Args>
	inline void Logger::Info(const char* message, Args ... args)
	{
		//--printing
		Logger::printer(LogPriority::Info, LogPriority::Warn, 32, message, "[Info]", args...);

	}

	template<typename ...Args>
	inline void Logger::Warn(const char* message, Args ... args)
	{
		//--printing
		Logger::printer(LogPriority::Warn, LogPriority::Error, 33, message, "[Warn]", args...);

	}

	template<typename ...Args>
	inline void Logger::Error(const char* message, Args ... args)
	{

		//--printing
		Logger::printer(LogPriority::Error, LogPriority::Fatal, 31, message, "[Error]", args...);

	}

	template<typename ...Args>
	inline void Logger::Fatal(const char* message, Args ... args)
	{

		//--printing
		Logger::printer(LogPriority::Fatal, LogPriority::Fatal, 31, message, "[Fatal]", args...);


	}

	//----Printer Macros

#define LOG_TRACE(message,... )  Logger::Trace(message,__VA_ARGS__)
#define LOG_INFO(... )			 Logger::Info(__VA_ARGS__)
#define LOG_WARN(... )			 Logger::Warn(__VA_ARGS__)
#define LOG_ERROR(message,... )  Logger::Error(message,__VA_ARGS__)
#define LOG_FATAL(... )			 Logger::Fatal(__VA_ARGS__)

}