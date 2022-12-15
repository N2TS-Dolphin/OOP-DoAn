#include "GPAGenerator.h"

#include <ctime>
#include <sstream>
#include <vector>

#include "IntegerGenerator.h"

GPAGenerator::GPAGenerator()
{
	srand(time(NULL));
}

string GPAGenerator::next()
{
	IntegerGenerator* IntGen = IntegerGenerator::instance();
	stringstream builder;
	int num = IntGen->next(4);
	int decimal = IntGen->next(100);

	if (decimal < 10)
		builder << num << ".0" << decimal;
	else
		builder << num << "." << decimal;

	string result = builder.str();
	return result;
}