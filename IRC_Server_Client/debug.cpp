#include <string>
#include <iostream>
#include "debug.h"


using namespace std;


//generic
void debug::WriteMessage(const std::string& message)
{
	cout << message << endl;
}
//generic 


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
		debug::WriteMessage(message);
	}
}


void debug::WriteImportantMessage(const std::string message)
{
	if (m_DebugLevel == DebugLevel::CriticalLevel ||
		m_DebugLevel == DebugLevel::ImportantLevel)
	{
		debug::WriteMessage(message);
	}
}


void debug::WriteInformationalMessage(const std::string message)
{
	if (m_DebugLevel == DebugLevel::InformationalLevel)
	{
		debug::WriteMessage(message);
	}
}

