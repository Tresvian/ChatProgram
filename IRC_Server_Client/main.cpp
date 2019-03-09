#include "IRC_Program.h"
#include <exception>
#include <iostream>


int main(int argc, char* argv[])
{
	try
	{
		IRC_Program();
	}
	catch (std::exception &e)
	{
		// todo
		std::cout << e.what() << std::endl;
		system("pause");
		return 1;
	}

	return 0;
}