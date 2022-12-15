#pragma once
#include <iostream>

using namespace std;

class IntegerGenerator
{
private:
	inline static IntegerGenerator* _instance = NULL;
	IntegerGenerator();

public:
	static IntegerGenerator* instance();
	int getRandNum();
	int getRandNum(int);
	int getRandNum(int, int);
};