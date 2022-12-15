#include "StudentIDGenerator.h"

#include <sstream>

#include "IntegerGenerator.h"
#include "Major.h"

StudentIDGenerator::StudentIDGenerator()
{
	srand(time(NULL));
}

string StudentIDGenerator::next(string& Majors)
{
	IntegerGenerator* IntGen = IntegerGenerator::instance();

	const int year = 2022;

	int tmp = IntGen->next(4);
	int major = 0;

	switch (tmp)
	{
	case 0:
		major = Major::IT; //IT
		Majors = "Cong nghe thong tin";
		break;
	case 1:
		major = Major::Chemistry; //Chemistry
		Majors = "Hoa hoc";
		break;
	case 2:
		major = Major::Physics; //Physics
		Majors = "Vat li";
		break;
	case 3:
		major = Major::Biology; //Biology
		Majors = "Sinh hoc";
		break;
	}

	string result = next(year, major);
	return result;
}

/// <summary>
/// Tao MSSV
/// </summary>
/// <param name="year">Nam hoc</param>
/// <param name="major">Chuyen nganh</param>
/// <returns></returns>
string StudentIDGenerator::next(int year, int major)
{
	stringstream builder;
	builder << year % 100 << major;

	auto IntGen = IntegerGenerator::instance();

	for (int i = 1; i <= 4; i++)
	{
		int digit = IntGen->next(10);
		builder << digit;
	}

	string result = builder.str();
	return result;
}