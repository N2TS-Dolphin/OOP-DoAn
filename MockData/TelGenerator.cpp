#include "TelGenerator.h"

#include <ctime>
#include <sstream>
#include <vector>

#include "IntegerGenerator.h"

TelGenerator::TelGenerator()
{
	srand(time(NULL));
}

string TelGenerator::next()
{
	IntegerGenerator* IntGen = IntegerGenerator::instance();
	vector <string> prefix = { "032","033","034","035","036","037","038","039","070","079","077","076","078","083","084","085","081","082","056","058","059" };
	stringstream builder;

	builder << prefix[IntGen->next(prefix.size())];

	for (int i = 0; i < 7; i++)
		builder << IntGen->next(10);

	string result = builder.str();
	return result;
}