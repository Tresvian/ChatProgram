#include "IRC_Program.h"


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
	// End debugger


	// Start main routine.
	debug::WriteImportantMessage(std::string("Starting main routine"));

	// Creating atomic bool to signal for end or not.
	std::atomic<bool> endProgramIndicator( false );

	// connection to OS
	boost::asio::io_context iocontext;

	std::thread chatInstance(Chat(iocontext, 5005, 10, endProgramIndicator));

	IdlePrompt(endProgramIndicator);

	return 0;
	
}

static int IdlePrompt(std::atomic<bool>& endProgramIndicator)
{
	using namespace std;
	string command;

	while (cin >> command)
	{
		// I'd prefer to change this so it's splitting, looking for "/" and then search command - followed by args.
		if (command == string("/help"))
		{
			cout << "Supported commands:\n"
					"/help            Shows this menu\n"
					"/quit            Sends signal to stop the program\n"
					"/show            Shows the current users on the server\n"
					"/ban             Bans a user\n"
					"/changepassword  Changes a user's password\n"
					"/message         Send server wide message\n"
				<< endl;
			continue;
		}
		if (command == string("/quit"))
		{
			endProgramIndicator = true;
			break;
		}
		if (command == string("/show"))
		{
			// todo
			continue;
		}
		if (command == string("/ban"))
		{
			// todo ban user from sql list
			continue;
		}
		if (command == string("/changepassword"))
		{
			// todo change user password
			continue;
		}
		if (command == string("/message"))
		{
			// todo change user password
			continue;
		}
		else
		{
			debug::WriteInformationalMessage(std::string("Ran unrecognizable command in idle prompt"));
		}
	}
}

