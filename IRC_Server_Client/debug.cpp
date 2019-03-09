#include <string>
#include <iostream>
#include "debug.h"


using namespace std;


void debug::WriteMessage(const std::string& message, DebugLevel level) //generic 
{
	if (level == DebugLevel::CriticalLevel)
		cout << "[CRITICAL] " << message << endl;

	else if (level == DebugLevel::ImportantLevel)
		cout << "[IMPORTANT] " << message << endl;

	else if (level == DebugLevel::InformationalLevel)
		cout << "[INFORMATIONAL] " << message << endl;
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

