#pragma once
#include <string>
#include <iostream>
/*
Sets friendly console logging into the window.

Each level (in enum class DebugLevel) cooresponds to the level we want to message.

NoLevel        messages nothing.
CriticalLevel  messages only critical.
ImportantLevel messages both Critical and Important.
Informational  messages Critical, Important, and Informational.

Use SetDebugLevel(ENUM DebugLevel) for the levels.

Write"LEVEL"(string message) for outputting.
*/


enum class DebugLevel
{
	NoLevel, CriticalLevel, ImportantLevel, InformationalLevel
};


// debug will never be instantiated.
class debug {
private:
	debug() = delete;
	~debug() = delete;
	static DebugLevel m_DebugLevel;

	// Generic
	static void WriteMessage(const std::string& message, DebugLevel level);

public:
	
	static void SetDebugLevel(DebugLevel x);

	static void WriteCriticalMessage (const std::string message);

	static void WriteImportantMessage (const std::string message);

	static void WriteInformationalMessage (const std::string message);	
};

