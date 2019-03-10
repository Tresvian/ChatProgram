#include "IRC_Program.h"
#include <exception>
#include <iostream>
#include <vector>
#include <string>
/*
	argv[1] will be reserved for debug:
		NoLevel        messages nothing.
		CriticalLevel  messages only critical.
		ImportantLevel messages both Critical and Important.
		Informational  messages Critical, Important, and Informational.

*/

int main(int argc, char* argv[])
{
	// Transfer argv into a vector
	std::vector<std::string> argVector;

	for (int i = 1; argc < i; ++i)
	{
		argVector.push_back(argv[i]);
	}

	// Initialize, pass in args
	try
	{
		IRC_Program(argVector);
	}

	// Exception Handling
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		system("pause");
		return 1;
	}

	return 0;
}