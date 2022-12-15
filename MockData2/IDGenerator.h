#pragma once
#include <iostream>

using namespace std;

class IDGenerator
{
public:
	IDGenerator();
	string next();
	string next(int, int);
};