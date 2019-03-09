#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> GetInput()
{
	string temp;
	vector<string> returnVal;

	while (getline(cin, temp))
	{
		returnVal.push_back(temp);
	}

	return returnVal;
}