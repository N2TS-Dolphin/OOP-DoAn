#include "EmailGenerator.h"

#include <ctime>
#include <vector>
#include <sstream>
#include <ctime>

#include "Utils.h"
#include "IntegerGenerator.h"

EmailGenerator::EmailGenerator()
{
	srand(time(NULL));
}

string EmailGenerator::next(string name)
{
	vector <string> tokens = Utils::String::split(name, " ");
	vector <string> domains = { "apple.com", "gmail.com", "outlook.com", "yahoo.com" };
	IntegerGenerator* IntGen = IntegerGenerator::instance();
	stringstream builder;

	for (int i = 0; i < tokens.size(); i++)
		builder << (char)(tokens[i][0] + 32);

	int tmp = IntGen->next(1000);
	if (tmp == 0)
		builder << "@" << domains[IntGen->next(domains.size())];
	else
		builder << tmp << "@" << domains[IntGen->next(domains.size())];

	string result = builder.str();
	return result;
}