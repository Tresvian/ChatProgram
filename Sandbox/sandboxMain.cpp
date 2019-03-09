// THIS IS ONLY FOR SANDBOXING
#include <string>
#include <iostream>
#include <ctype.h>
#include <vector>


std::vector<std::string> Split(std::string &s)
{
	std::string::size_type i = 0;
	std::vector<std::string> result;

	while (i != s.size())
	{
		while (i != s.size() && isspace(s[i]))
		{
			++i;
		}

		std::string::size_type j = i;
		while (j != s.size() && !isspace(s[j]))
		{
			++j;
		}
		
		if (i != j)
		{
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}

	return result;
}

int main(int argc, char* argv[])
{
	
	std::string stringToParse = "asldfjadlkf alskjdfjdlk flemif";

	std::vector<std::string> results = Split(stringToParse);

	for (std::vector<std::string>::iterator iter = results.begin();
		iter != results.end();
		++iter)
	{
		std::cout << *iter << std::endl;
	}


	std::cin.get();

	return 0;
}