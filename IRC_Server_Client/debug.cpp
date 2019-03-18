#include "debug.h"

using namespace std;

DebugLevel debug::m_DebugLevel = DebugLevel::NoLevel;

shared_ptr<vector<string>> debug::m_ConsoleLog = make_shared<vector<string>>();

void debug::WriteMessage(const string& message, DebugLevel level) //generic 
{
	// Make sure size isn't getting out of control here.
	if (m_ConsoleLog->size() > 1000)
	{
		m_ConsoleLog->erase(m_ConsoleLog->begin());
	}

	// Write message according to passed in DebugLevel
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
	debug::m_DebugLevel = x;
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
	fstream file("IRC_Program_Log.txt");

	for (const auto &EveryLine : *m_ConsoleLog)
	{
		file << EveryLine << "\n";
	}
}
