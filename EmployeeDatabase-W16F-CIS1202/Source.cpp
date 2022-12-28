/*
* Kurt Kangas
* CIS 1202 C++ Programming II
* Week 16 Project
* Employee Database (I/O Binary)
*/
#include "Employee_C.h"

Employee_C* Fill_Array();
void Extract_ID(Employee_C* arr, fstream& bName, fstream& tName);
int Find_Employee(int id, fstream& bName, fstream& tName);

int main()
{
	fstream txt, bin;
	string txtName, binName;
	int id;
	cout << "\nEnter the binary file name> ";
	getline(cin, txtName);
	binName = txtName;

	Employee_C employeeArray[SIZE];
	Employee_C* employee_array = Fill_Array();

	txt.open(txtName, ios::out);
	bin.open(binName, ios::out | ios::binary);
	Extract_ID(employee_array, bin, txt);
	txt.close();
	bin.close();

	bool again = true;
	while (again)
	{
		cout << "\nEnter the ID of the employee> ";
		cin >> id;

		txt.open(txtName, ios::in);
		bin.open(binName, ios::in | ios::binary);
		if (txt.fail() || bin.fail())
		{
			cout << "\nError...Unable to open file...";
			system("pause");
			return 0;
		}
		int target = Find_Employee(id, bin, txt);
		txt.close();
		bin.close();

		if (target == -1)
		{
			cout << "Error! No Employee with ID entered" << endl;
		}
		else
		{
			Employee_C employee = employee_array[target - 1];
			cout << "Employee Name: " << employee.Get_Name() << endl;
			cout << "Employee ID: " << employee.Get_IDNumber() << endl;
			cout << "Employee Salary: " << employee.Get_Salary() << endl;
			cout << "Employee Gender: " << employee.Get_Gender() << endl;
			cout << "Total Salaries: " << employee.Get_TotalSalaries() << endl;
		}
		cout << "\nSearch for another employee? 1 for Yes, else enter 0>";
		cin >> again;
	}
	delete[] employee_array;
	cout << endl << endl;
	system("pause");
	return 0;
}
Employee_C* Fill_Array()
{
	Employee_C* array1 = new Employee_C[100];
	Employee_C array2;
	array2.Set_IDNumber(-1);

	for (int i = 0; i < 100; i++)
	{
		array1[i] = array2;
	}

	int startCounter = 0;
	string name;
	int id;
	int salary;
	char gender;

	bool again = true;
	while (again)
	{
		Employee_C employee;
		cout << "\nEnter Employee's Name> ";
		if (startCounter != 0)
			cin.ignore();
		getline(cin, name, '\n');
		cout << "Enter Employee's ID> ";
		cin >> id;
		cout << "Enter Employee's salary> ";
		cin >> salary;
		cout << "Enter Employee's gender> ";
		cin >> gender;

		employee.Set_Name(name);
		employee.Set_Gender(gender);
		employee.Set_IDNumber(id);
		employee.Set_Salary(salary);

		array1[startCounter] = employee;
		startCounter++;

		cout << "\nProcess another employee? 1 for Yes else enter 0>";
		cin >> again;
	}
	return array1;
}
void Extract_ID(Employee_C* array1, fstream& bName, fstream& tName)
{
	for (int i = 0; i < 100; i++)
	{
		if (array1[i].Get_IDNumber() == -1) return;
		bName << array1[i].Get_IDNumber();
		bName << "\n";
		tName << array1[i].Get_IDNumber();
		tName << "\n";
	}
	return;
}

int Find_Employee(int id, fstream& bName, fstream& tName)
{
	if (!bName) {
		cout << "Error...Unable to open file..." << endl;
		exit(1);
	}
	string employeeInfo;
	string scan = to_string(id);
	size_t target;
	int num = 0;
	while (bName.good())
	{
		getline(bName, employeeInfo);
		num++;
		target = employeeInfo.find(scan);
		if (target != string::npos)
		{
			return num;
			bName.close();
			break;
		}
	}
	return -1;
}