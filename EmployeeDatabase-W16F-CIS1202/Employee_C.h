#ifndef Employee_C_
#define Employee_C_

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

const int SIZE = 100;

class Employee_C
{
private:
	string Name;
	int IDNumber;
	double Salary;
	char Gender;
	static double TotalSalaries;

public:
	Employee_C();
	Employee_C(double);
	Employee_C(string, int, double, char);

	// Setters
	void Set_Name(string);
	void Set_IDNumber(int);
	void Set_Salary(double);
	void Set_Gender(char);


	// Getters
	string Get_Name() const;
	int Get_IDNumber() const;
	double Get_Salary() const;
	char Get_Gender() const;

	double Get_TotalSalaries() const;

};
#endif
