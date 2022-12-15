#include "FullNameGenerator.h"

#include <sstream>
#include <vector>
#include <ctime>

#include "IntegerGenerator.h"

FullNameGenerator::FullNameGenerator()
{
	srand(time(NULL));
}

string FullNameGenerator::next()
{
	vector<string> first_name = { "Nguyen ", "Tran ", "Ly ", "Dinh ", "Le ", "Vo " };
	vector<string> middle_name = { "Thanh ", "Thi ", "Van ", "Hoai ", "Minh ", "Mai " };
	vector<string> last_name = { "Son", "Nhu", "Huyen", "Tam", "Manh", "Hong" };
	int i;

	IntegerGenerator* IntGen = IntegerGenerator::instance();
	i = IntGen->next(first_name.size());
	string first = first_name[i];

	i = IntGen->next(middle_name.size());
	string middle = middle_name[i];

	i = IntGen->next(last_name.size());
	string last = last_name[i];

	stringstream builder;
	builder << first << middle << last;

	string result = builder.str();
	return result;
}