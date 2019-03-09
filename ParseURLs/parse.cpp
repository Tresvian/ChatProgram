#include <vector>
#include <string>
#include <algorithm>

bool CheckForProtocol(std::string &x)
{
	// checker for "://" is in input
	bool result;
	
	return result;
}


std::vector<std::string> SearchURL(std::vector<std::string> &rawinput)
{
	using namespace std;
	vector<string> returnResult;

	// iterate through each item in vector
	for (string eachString : rawinput)
	{
		// check if "://" is ever found first.
		if (CheckForProtocol(eachString))
			continue;

		// iterate through each char in string if URL indicator true, and return the URL
		for (string::iterator iter = eachString.begin(); iter != eachString.end(); ++iter)
		{

		}
	}



}