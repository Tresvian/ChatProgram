#include "IRC_Program.h"
#include "debug.h"


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
	int returnResult;

	for (int i = 1; i < argc ; ++i)
	{
		argVector.push_back(argv[i]);
	}

	// Initialize, pass in args
	returnResult = IRC_Program(argVector);

	std::cout << "Program exited gracefully" << std::endl;
	debug::WriteCriticalMessage(std::string("Program exited successfully"));
	system("pause");
	return returnResult;
}