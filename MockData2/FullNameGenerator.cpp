#include "FullNameGenerator.h"

#include <ctime>
#include <vector>
#include <sstream>

#include "IntGenerator.h"

FullNameGenerator::FullNameGenerator()
{
	srand(time(NULL));
}

string FullNameGenerator::next()
{
	vector <string> first_name = { "Nguyen ","Tran ","Le ","Vo ","Huynh ","Pham " };
	vector <string> middle_name = { "Thanh ","Thi ","Mai ","Van ","Vinh ","Hoang " };
	vector <string> last_name = { "Son","Thao","Minh","Huy","Chi","Quynh" };

	IntegerGenerator* IntGen = IntegerGenerator::instance();
	stringstream builder;

	string first = first_name[IntGen->getRandNum(first_name.size())];
	string middle = middle_name[IntGen->getRandNum(middle_name.size())];
	string last = last_name[IntGen->getRandNum(last_name.size())];

	builder << first << middle << last;

	string result = builder.str();
	return result;
}