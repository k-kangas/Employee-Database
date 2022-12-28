#include "Employee_C.h"

double Employee_C::TotalSalaries = 0;


Employee_C::Employee_C()
{
	Name = "";
	IDNumber = 0;
	Salary = 0;
	Gender = '\u0000';
}

Employee_C::Employee_C(double sal)
{
	TotalSalaries += sal;
}

Employee_C::Employee_C(string nm, int idnum, double sal, char gen)
{
	Name = nm;
	IDNumber = idnum;
	Salary = sal;
	Gender = gen;
	TotalSalaries += sal;
}

void Employee_C::Set_Name(string nm)
{
	Name = nm;
}

void Employee_C::Set_IDNumber(int idnum)
{
	IDNumber = idnum;
}

void Employee_C::Set_Salary(double sal)
{
	Salary = sal;
	TotalSalaries += sal;
}

void Employee_C::Set_Gender(char gen)
{
	Gender = gen;
}

string Employee_C::Get_Name() const
{
	return Name;
}

int Employee_C::Get_IDNumber() const
{
	return IDNumber;
}

double Employee_C::Get_Salary() const
{
	return Salary;
}

char Employee_C::Get_Gender() const
{
	return Gender;
}

double Employee_C::Get_TotalSalaries() const
{
	return TotalSalaries;
}
