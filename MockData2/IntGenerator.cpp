#include "IntGenerator.h"

#include <ctime>

IntegerGenerator::IntegerGenerator()
{
	srand(time(NULL));
}

IntegerGenerator* IntegerGenerator::instance()
{
    if (_instance == NULL) {
        _instance = new IntegerGenerator();
    }

    return _instance;
}

int IntegerGenerator::getRandNum() {
    int result = rand();
    return result;
}

int IntegerGenerator::getRandNum(int max) {
    int result = rand() % max;
    return result;
}

int IntegerGenerator::getRandNum(int left, int right) {
    int result = rand() % (right - left + 1) + left;
    return result;
}