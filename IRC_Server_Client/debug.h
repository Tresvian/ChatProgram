#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <string>
/*
Sets friendly console logging into the window.

Each level (in enum class DebugLevel) cooresponds to the level we want to message.

NoLevel        messages nothing.
CriticalLevel  messages only critical.
ImportantLevel messages both Critical and Important.
Informational  messages Critical, Important, and Informational.

debug::WriteLEVEL(string message) for outputting.
*/


enum class DebugLevel
{
	NoLevel, CriticalLevel, ImportantLevel, InformationalLevel
};


namespace debug {

	DebugLevel m_DebugLevel;

	static std::vector<std::string>* m_ConsoleLog;

	static void WriteMessage(const std::string& message, DebugLevel level); // Generic
	
	static void SetDebugLevel(DebugLevel x);

	static void WriteCriticalMessage (const std::string message);

	static void WriteImportantMessage (const std::string message);

	static void WriteInformationalMessage (const std::string message);

	static void OutLogDump();
};

