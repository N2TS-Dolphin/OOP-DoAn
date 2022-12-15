#include "IDGenerator.h"

#include <ctime>
#include <sstream>

#include "IntGenerator.h"

IDGenerator::IDGenerator()
{
	srand(time(NULL));
}

string IDGenerator::next()
{
	const int year = 2022;
	const int major = 12;

	string result = next(year, major);
	return result;
}

string IDGenerator::next(int year, int major)
{
	stringstream builder;
	builder << year % 100 << major;

	auto IntGen = IntegerGenerator::instance();

	for (int i = 1; i <= 4; i++)
	{
		int digit = IntGen->getRandNum(10);
		builder << digit;
	}

	string result = builder.str();
	return result;
}