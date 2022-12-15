#include "BirthdayGenerator.h"

#include <ctime>
#include <sstream>

#include "IntegerGenerator.h"

BirthdayGenerator::BirthdayGenerator()
{
	srand(time(NULL));
}

string BirthdayGenerator::next()
{
	const int MAX_AGE = 118;
	int year, month, day;
	IntegerGenerator* IntGen = IntegerGenerator::instance();

	year = 1900 + IntGen->next(MAX_AGE);
	month = IntGen->next(1, 12);

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		day = IntGen->next(1, 31);
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		day = IntGen->next(1, 30);
	}
	else
	{
		if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		{
			day = IntGen->next(1, 29);
		}
		else
		{
			day = IntGen->next(1, 28);
		}
	}

	stringstream builder;
	builder << day << "/" << month << "/" << year;

	string result = builder.str();
	return result;
}