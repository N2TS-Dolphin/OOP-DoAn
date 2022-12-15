#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

#include "IntegerGenerator.h"
#include "StudentIDGenerator.h"
#include "FullNameGenerator.h"
#include "BirthdayGenerator.h"
#include "TelGenerator.h"
#include "EmailGenerator.h"
#include "AddressGenerator.h"
#include "GPAGenerator.h"

int main()
{
	ofstream out;
	out.open("Student.txt");

	if (!out.is_open())
	{
		cout << "ERROR";
		return 0;
	}

	IntegerGenerator* IntGen = IntegerGenerator::instance();

	StudentIDGenerator StuID;
	FullNameGenerator StuName;
	BirthdayGenerator StuBirth;
	TelGenerator StuTel;
	EmailGenerator StuEmail;
	AddressGenerator StuAddress;
	GPAGenerator StuGPA;

	for (int i = 0; i < 30; i++)
	{
		int tmp = IntGen->next(2);
		string Majors;
		if (tmp == 0)
		{
			vector <string> student = { StuID.next(Majors), StuName.next(), StuBirth.next() };
			student.push_back(Majors);
			student.push_back(StuTel.next());
			student.push_back(StuEmail.next(student[1]));
			student.push_back(StuAddress.next());
			student.push_back(StuGPA.next());

			cout << "Student ID: " << student[0] << endl;
			cout << "Name: " << student[1] << endl;
			cout << "Birthday: " << student[2] << endl;
			cout << "Major: " << student[3] << endl;
			cout << "Tel: " << student[4] << endl;
			cout << "Email: " << student[5] << endl;
			cout << "Address: " << student[6] << endl;
			cout << "GPA: " << student[7] << endl << endl;

			out << "Student ID: " << student[0] << endl;
			out << "Name: " << student[1] << endl;
			out << "Birthday: " << student[2] << endl;
			out << "Major: " << student[3] << endl;
			out << "Tel: " << student[4] << endl;
			out << "Email: " << student[5] << endl;
			out << "Address: " << student[6] << endl;
			out << "GPA: " << student[7] << endl << endl;
		}
		else
		{
			vector <string> student = { StuID.next(Majors), StuName.next(), StuBirth.next() };
			student.push_back(Majors);
			student.push_back(StuTel.next());
			student.push_back(StuTel.next());
			student.push_back(StuEmail.next(student[1]));
			student.push_back(StuAddress.next());
			student.push_back(StuGPA.next());

			cout << "Student ID: " << student[0] << endl;
			cout << "Name: " << student[1] << endl;
			cout << "Birthday: " << student[2] << endl;
			cout << "Major: " << student[3] << endl;
			cout << "Tel 1: " << student[4] << endl;
			cout << "Tel 2: " << student[5] << endl;
			cout << "Email: " << student[6] << endl;
			cout << "Address: " << student[7] << endl;
			cout << "GPA: " << student[8] << endl << endl;

			out << "Student ID: " << student[0] << endl;
			out << "Name: " << student[1] << endl;
			out << "Birthday: " << student[2] << endl;
			out << "Major: " << student[3] << endl;
			out << "Tel 1: " << student[4] << endl;
			out << "Tel 2: " << student[5] << endl;
			out << "Email: " << student[6] << endl;
			out << "Address: " << student[7] << endl;
			out << "GPA: " << student[8] << endl << endl;
		}
	}
}