#include <string>
#include <iostream>
#include "debug.h"


using namespace std;


//generic
void debug::WriteMessage(std::string message)
{
	cout << message << endl;
}
//generic 


void debug::SetDebugLevel(DebugLevel x)
{
	m_DebugLevel = x;
}


void debug::WriteCriticalMessage(std::string message)
{
	if (m_DebugLevel == DebugLevel::CriticalLevel ||
		m_DebugLevel == DebugLevel::ImportantLevel ||
		m_DebugLevel == DebugLevel::InformationalLevel)
	{
		debug::WriteMessage(message);
	}
}


void debug::WriteImportantMessage(std::string message)
{
	if (m_DebugLevel == DebugLevel::CriticalLevel ||
		m_DebugLevel == DebugLevel::ImportantLevel)
	{
		debug::WriteMessage(message);
	}
}



void debug::WriteInformationalMessage(std::string message)
{
	if (m_DebugLevel == DebugLevel::InformationalLevel)
	{
		debug::WriteMessage(message);
	}
}

