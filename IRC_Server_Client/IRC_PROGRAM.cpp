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
				debug::SetDebugLevel(DebugLevel::InformationalLevel);
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
			debug::WriteImportantMessage(std::string("Passed in argument: ") + eachArg);
		}
	}
	else
	{
		debug::SetDebugLevel(DebugLevel::NoLevel);
	}
	// End debugger signature


	debug::WriteImportantMessage(std::string("Starting main routine"));


	// Start main routine.
	int tickRate;


	std::cout << "Enter the tick rate in milliseconds:" << std::endl;
	std::cin >> tickRate;

	while (std::cin.fail())
	{
		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		debug::WriteCriticalMessage(std::string("Invalid tick rate entered"));

		std::cout << "Please enter a proper tick rate." << std::endl;

		std::cin >> tickRate;
	}
	

	
	// todo::add in networkFactory.h functions to begin tcp functions

	return 0;
}