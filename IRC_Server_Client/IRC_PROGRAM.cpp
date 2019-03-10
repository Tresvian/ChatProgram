#include <vector>
#include <string>
#include "debug.h"

int IRC_Program(const std::vector<std::string>& args)
{
	// Set Debugger Level by arg, otherwise NoLevel by default.
	if (!args.empty())
	{
		for (std::string eachArg : args)
		{
			if (eachArg == std::string("CriticalLevel"))
			{
				debug::SetDebugLevel(DebugLevel::CriticalLevel);
				debug::WriteInformationalMessage(std::string("Started debugger at CriticalLevel"));
				continue;
			}
			else if (eachArg == std::string("ImportantLevel"))
			{
				debug::SetDebugLevel(DebugLevel::ImportantLevel);
				debug::WriteInformationalMessage(std::string("Started debugger at ImportantLevel"));
				continue;
			}
			else if (eachArg == std::string("InformationalLevel"))
			{
				debug::SetDebugLevel(DebugLevel::InformationalLevel);
				debug::WriteInformationalMessage(std::string("Started debugger at InformationaLevel"));
				continue;
			}
			else
			{
				debug::SetDebugLevel(DebugLevel::NoLevel);
			}
			debug::WriteImportantMessage(std::string("Passed in argument: ") + eachArg);
		}
	}
	// End debugger signature


	debug::WriteImportantMessage(std::string("Starting main routine"));


	// Start main routine.
	int tickRate;
	bool validTickRate = false;


	std::cout << "Enter the tick rate in milliseconds:" << std::endl;
	while (!validTickRate)
	{
		validTickRate = true;

		std::cin >> tickRate;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Please enter a proper tick rate." << std::endl;
			validTickRate = false;
			debug::WriteCriticalMessage(std::string("Invalid tick rate entered"));
		}
	}
	

	
	// todo::add in networkFactory.h functions to begin tcp functions

	return 0;
}