#include "Utils.h"

vector<string> Utils::String::split(string haystack, string needle) 
{
	vector<string> result;

	int startPos = 0;
	size_t foundPos = haystack.find(needle, startPos);

	while (foundPos != string::npos) 
	{
		int count = foundPos - startPos;
		string token = haystack.substr(startPos, count);
		result.push_back(token);

		startPos = foundPos + needle.length();
		foundPos = haystack.find(needle, startPos);
	}

	// Remaining substring
	string token = haystack.substr(startPos, haystack.length() - startPos);
	result.push_back(token);

	return result;
}