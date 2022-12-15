#include "AddressGenerator.h"

#include <ctime>
#include <vector>
#include <sstream>

#include "IntegerGenerator.h"

AddressGenerator::AddressGenerator()
{
	srand(time(NULL));
}

string AddressGenerator::next()
{
	stringstream builder;
	IntegerGenerator* IntGen = IntegerGenerator::instance();
	vector <string> Q = { "1", "3", "4", "5", "6", "7", "8", "10", "11", "Tan Binh", "Tan Phu", "Binh Thanh", "Phu Nhuan", "Go Vap" };
	int q = IntGen->next(14);
	vector <string> P;

	if (q == 0)
	{
		//Quan 1
		P = { "Tan Dinh", "Đa Kao", "Ben Nghe", "Ben Thanh", "Nguyen Thai Binh", "Pham Ngu Lao", "Cau Ong Lanh", "Co Giang", "Nguyen Cu Trinh", "Cau Kho" }; //10 phuong

	}
	else if (q == 1)
	{
		//Quan 3
		P = { "1", "2", "3", "4", "5", "9", "10", "11", "12", "13", "14", "Vo Thi Sau" }; //13 phuong

	}
	else if (q == 2)
	{
		//Quan 4
		P = { "1", "2", "3", "4", "6", "8", "9", "10", "13", "14", "15", "16", "18" }; //13 phuong

	}
	else if (q == 3)
	{
		//Quan 5
		P = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14" }; //14 phuong

	}
	else if (q == 4)
	{
		//Quan 6
		P = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14" }; //14 phuong

	}
	else if (q == 5)
	{
		//Quan 7
		P = {"Tan Thuan Dong", "Tan Thuan Tay", "Tan Kieng", "Tan Hung", "Binh Thuan", "Tan Quy", "Phu Thuan", "Tan Phu", "Tan Phong", "Phu My" }; //10 phuong

	}
	else if (q == 6)
	{
		//Quan 8
		P = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16" }; //16 phuong

	}
	else if (q == 7)
	{
		//Quan 10
		P = { "1", "2", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15" }; //14 phuong

	}
	else if (q == 8)
	{
		//Quan 11
		P = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"}; //16 phuong

	}
	else if (q == 9)
	{
		//Quan Tan Binh
		P = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15" }; //15 phuong

	}
	else if (q == 10)
	{
		//Quan Tan Phu
		P = { "Tan Son Nhi", "Tay Thanh", "Son Ky", "Tan Quy", "Tan Thanh", "Phu Tho Hoa", "Phu Thanh", "Phu Trung", "Hoa Thanh", "Hiep Tan", "Tan Thoi Hoa" }; //11 phuong

	}
	else if (q == 11)
	{
		//Huyen Binh Chanh
		P = { "Thi tran Tan Tuc", "Pham Van Hai", "Vinh Loc A", "Vinh Loc B", "Binh Loi", "Le Minh Xuan", "Tan Nhut", "Tan Kien", "Binh Hung", "Phong Phu", "An Phu Tay", "Hung Long", "Da Phuoc", "Tan Quy Tay", "Binh Chanh", "Quy Duc" }; //16 phuong

	}
	else if (q == 12)
	{
		//Quan Phu Nhuan
		P = { "1", "2", "3", "4", "5", "7", "8", "9", "10", "11", "13", "15", "17" }; //13 phuong

	}
	else if (q == 13)
	{
		//Quan Go Vap
		P = { "1", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17" }; //16 phuong

	}

	int p = IntGen->next(P.size());
	vector <string> street = { "Phan Boi Chau", "Cong Hoa", "3 thang 2", "Ly Thuong Kiet", "Le Dai Hanh", "Hong Bang", "Nguyen Van Cu", "Nguyen Van Linh", "30 thang 4", "Nguyen Thi Minh Khai", "Dao Duy Tu", "Nguyen Hong", "Binh Quoi", "Dien Bien Phu", "Cach Mang Thang 8", "Le Hong Phong", "Pho Co Dieu" };
	int s = IntGen->next(street.size());

	int sonha = IntGen->next(10, 600);
	int sonha2 = IntGen->next(3);
	string sonha3;

	if (sonha2 == 0)
		sonha3 = "A";
	else if (sonha2 == 1)
		sonha3 = "B";
	else
		sonha3 = "";

	builder << sonha << sonha3 << ", duong " << street[s];

	if (q == 11)
	{
		if (p == 0)
			builder << ", " << P[p] << ", Quan " << Q[q];
		else
			builder << ", Xa " << P[p] << ", Quan " << Q[q];
	}
	else
	{
		builder << ", Phuong " << P[p] << ", Quan " << Q[q];
	}

	builder << ", Thanh pho Ho Chi Minh";

	string result = builder.str();
	return result;
}