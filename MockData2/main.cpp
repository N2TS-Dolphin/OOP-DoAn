#include <iostream>

using namespace std;

#include "IDGenerator.h"
#include "IntGenerator.h"
#include "FullNameGenerator.h"
#include "EmailGenerator.h"

int main()
{
	FullNameGenerator nameGen;
	EmailGenerator mailGen;

	cout << mailGen.next(nameGen.next());
}