#include "company.h"
#include<iostream>
#include<string>
using namespace std;

company::company()
{

}

　
company::~company()
{
}

void company::createNewEmployee()
{
	string pro;
	string name;
	string dept;
	int year=0;
	int salary=0;
	employee.id++;
	cout << "\nEmployee id " << employee.id << "\n";
	employee.employee_id.push_back(employee.id);
	   
	cout << "\nEnter employee name ";
	cin >> name;
	employee.employee_name.push_back(name);

	cout << "\nEnter Project name ";
	cin >> pro;
	employee.project_name.push_back(pro);

	cout << "\nEnter department ";
	cin >> dept;
	employee.department.push_back(dept);

	while (year<1970||year > 2018)
	{
		cout << "\nEnter year of joining ";
		year = validation();
	}

	
	employee.year_of_joining.push_back(year);

	cout << "\nEnter Pay ";
	salary = validation();
	employee.pay.push_back(salary);
}
int company::validation()
{
	int error=0;
	int num=0;
	do
	{
		error = 0;

		cin >> num;
		if (cin.fail())
		{
			cout << "\nPlease enter a valid integer" << endl;
			error = 1;
		}
	} while (error == 1);
	return num;
}

void company::displayDetails()
{
	int iterate=0;
	cout << "\nEmp id\t\tEmp Name\tProject Name\tDepartment\tyear of joining\tPay";
	for (iterate = 0; iterate < employee.employee_id.size(); iterate++)
	{
		cout << "\n" << employee.employee_id[iterate] << "\t";
		cout << employee.employee_name[iterate] << "\t\t";
		cout << employee.project_name[iterate] << "\t\t";
		cout << employee.department[iterate] << "\t\t";
		cout << employee.year_of_joining[iterate] << "\t\t";
		cout << employee.pay[iterate] << "\n";
	}
}
void company::namesFromDateOfJoining()
{
	int doj=0;
	int iterate = 0;
	int flag=0;
	cout << "\nEnter year of joining ";
	doj = validation();
	for (iterate = 0; iterate < employee.employee_id.size(); iterate++)
	{
		if (employee.year_of_joining[iterate] == doj)
		{
			flag = 1;
			cout << "\n" << employee.employee_name[iterate];
		}

	}
	if (0 == flag)
	{
		cout << "\nInvalid year of joining";
	}
}
void company::employeeWithHighPay()
{
	int iterate = 0;
	int high = 0;
	int amount = 0;
	string dept;
	int flag = 0;
	cout << "\nEnter department ";
	cin >> dept;
	for (iterate = 0; iterate < employee.employee_id.size(); iterate++)
	{
		if (employee.department[iterate] == dept)
		{
			flag = 1;
			if (amount < employee.pay[iterate])
			{
				high = iterate;
			}
		}
	}
	if (1 == flag)
	{
		cout << "\nhighest Pay in " << dept << " department";
		cout << "\nEmployee id " << employee.employee_id[high];
		cout << "\nEmployee name " << employee.employee_name[high];
		cout << "\nProject name " << employee.project_name[high];
		cout << "\nYear of joining " << employee.year_of_joining[high];
		cout << "\nPay " << employee.pay[high];
	}
	else
	{
		cout << "\ndepartment not found ";
	}
}
int company::binarySearch(int temp_id)
{
	
	int size=0;
	int first=0;
	int middle=0;
	int last=0;
	size = employee.employee_id.size();
	last = size-1;
	cout << "\nbinary";
	while (first <= last)
	{
		middle = (first + last) / 2;
		if (employee.employee_id[middle] == temp_id)
		{
			return middle;
		}
		else if (employee.employee_id[middle] < temp_id)
		{
			first = middle + 1;
		}
		else if (employee.employee_id[middle] > temp_id)
		{
			last = middle - 1;
		}	
	}
	return -1;
}
void company::updatePay()
{
	int temp_id=0;
	
	int result=0;
	cout << "\n\nEnter employee id ";
	temp_id = validation();
	result = binarySearch(temp_id);
	if (-1 == result)
	{
		cout << "\nEmployee id not found ";
	}
	else
	{
		employee.pay[result] = employee.pay[result] + (employee.pay[result] * 0.05);
		cout << "\nUpdated successfully";
		
	}
}

　
void company::push()
{
	int id=0;
	int result=0;
	cout << "\n\nEnter employee id ";
	cin >> id;
	result = binarySearch(id);
	if (-1 == result)
	{
		cout << "\n\nEmployee not found";
	}
	else
	{
		cout << result;
		employee.bench.push_back(id);
		cout << "\n\nEmployee moved to bench";
		employee.department.at(result) = "  ";
		employee.project_name.at(result) = "  ";
		rear++;
	}
}
void company::pop()
{
	int index;
	string pro;
	string dept;
	int id;
	if (front>rear)
	{
		cout << "\nbench is empty";
	}
	else
	{
		cout << "\nEnter project name ";
		cin >> pro;
		cout << "\nEnter department ";
		cin >> dept;
		id = employee.bench[front];
		index = binarySearch(id);
		employee.department[index] = dept;
		employee.project_name[index] = pro;
		cout << "\nEmployee " << id<< " moved to project";
		front++;
	}
}
void company::viewBench()
{
	int iterate = 0;
	cout << "\nEmployees in bench\n";
	for (iterate = front; iterate < employee.employee_id.size(); iterate++)
	{
		cout << employee.bench[iterate] << endl;
	}
}
