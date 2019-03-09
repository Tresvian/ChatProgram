#include <string>
#include <iostream>
#include "debug.h"
#include <fstream>
#include <exception>

using namespace std;


void debug::WriteMessage(const std::string& message, DebugLevel level) //generic 
{
	if (level == DebugLevel::CriticalLevel)
	{
		cout << "[CRITICAL] " << message << endl;
		m_ConsoleLog->push_back(string("[CRITICAL] ") + message);
	}

	else if (level == DebugLevel::ImportantLevel)
	{
		cout << "[IMPORTANT] " << message << endl;
		m_ConsoleLog->push_back(string("[IMPORTANT] ") + message);
	}

	else if (level == DebugLevel::InformationalLevel)
	{
		cout << "[INFORMATIONAL] " << message << endl;
		m_ConsoleLog->push_back(string("[INFORMATIONAL] ") + message);
	}
}


void debug::SetDebugLevel(DebugLevel x)
{
	m_DebugLevel = x;
}


void debug::WriteCriticalMessage(const std::string message)
{
	if (m_DebugLevel == DebugLevel::CriticalLevel ||
		m_DebugLevel == DebugLevel::ImportantLevel ||
		m_DebugLevel == DebugLevel::InformationalLevel)
	{
		debug::WriteMessage(message, DebugLevel::CriticalLevel);
	}
}


void debug::WriteImportantMessage(const std::string message)
{
	if (m_DebugLevel == DebugLevel::CriticalLevel ||
		m_DebugLevel == DebugLevel::ImportantLevel)
	{
		debug::WriteMessage(message, DebugLevel::ImportantLevel);
	}
}


void debug::WriteInformationalMessage(const std::string message)
{
	if (m_DebugLevel == DebugLevel::InformationalLevel)
	{
		debug::WriteMessage(message, DebugLevel::InformationalLevel);
	}
}


void debug::OutLogDump()
{
	fstream* file;

	file->open("IRC_Program_Log.txt", fstream::out);

	for (const auto &EveryLine : *m_ConsoleLog)
	{
		*file << EveryLine << "\n";
	}

	file->close();
}
