#pragma once
#include <iostream>

using namespace std;


class StudentIDGenerator
{
public:
	StudentIDGenerator();
	string next(string&);
	string next(int, int);
};