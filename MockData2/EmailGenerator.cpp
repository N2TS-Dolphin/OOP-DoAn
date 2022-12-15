#include "Utils.h"
#include "EmailGenerator.h"

#include <sstream>
#include <ctime>
#include <vector>

#include "IntGenerator.h"

EmailGenerator::EmailGenerator()
{
	srand(time(NULL));
}

string EmailGenerator::next(string name)
{
	stringstream builder;
	IntegerGenerator* IntGen = IntegerGenerator::instance();
	vector <string> domains = { "apple.com","outlook.com","yahoo.com","gmail.com" };
	const string SEPARATOR = " ";

	vector <string> tmp = Utils::String::split(name, SEPARATOR);

	

	builder << (char)(tmp[0][0] + 32) << (char)(tmp[1][0] + 32) << (char)(tmp[2][0] + 32) << "@" << domains[IntGen->getRandNum(4)];

	string result = builder.str();
	return result;
}