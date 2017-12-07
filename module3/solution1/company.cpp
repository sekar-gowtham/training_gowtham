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

	string name;
	string dept;
	int year=0;
	int salary=0;
	emp.id++;
	cout << "\nEmployee id " << emp.id << "\n";
	emp.emp_id.push_back(emp.id);
	   
	cout << "\nEnter employee name ";
	cin >> name;
	emp.emp_name.push_back(name);

	cout << "\nEnter department ";
	cin >> dept;
	emp.department.push_back(dept);

	cout << "\nEnter year of joining ";
	year = validation();
	

	
	emp.year_of_joining.push_back(year);

	cout << "\nEnter Pay ";
	salary = validation();
	emp.pay.push_back(salary);
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
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == 1);
	return num;
}

void company::displayDetails()
{
	int i=0;
	for (i = 0; i < emp.emp_id.size(); i++)
	{
		cout << emp.emp_id[i] << "\t";
		cout << emp.emp_name[i] << "\t";
		cout << emp.department[i] << "\t";
		cout << emp.year_of_joining[i] << "\t";
		cout << emp.pay[i] << "\n";
	}
}
void company::namesFromDateOfJoining()
{
	int doj=0;
	int i=0;
	int flag=0;
	cout << "\nEnter year of joining ";
	doj = validation();
	for (i = 0; i < emp.emp_id.size(); i++)
	{
		if (emp.year_of_joining[i] == doj)
		{
			flag = 1;
			cout << "\n" << emp.emp_name[i];
		}

	}
	if (0 == flag)
	{
		cout << "\nInvalid year of joining";
	}
}
void company::employeeWithHighPay()
{
	int i = 0;
	int high = 0;
	int amount = 0;
	string dept;
	int flag = 0;
	cout << "\nEnter department ";
	cin >> dept;
	for (i = 0; i < emp.emp_id.size(); i++)
	{
		if (emp.department[i] == dept)
		{
			flag = 1;
			if (amount < emp.pay[i])
			{
				high = i;
			}
		}
	}
	if (1 == flag)
	{
		cout << "\nhighest Pay in " << dept << " department";
		cout << "\nEmployee id " << emp.emp_id[high];
		cout << "\nEmployee name " << emp.emp_name[high];
		cout << "\nYear of joining " << emp.year_of_joining[high];
		cout << "\nPay " << emp.pay[high];
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
	size = emp.emp_id.size();
	last = size-1;
	
	while (first <= last)
	{
		middle = (first + last) / 2;
		if (emp.emp_id[middle] == temp_id)
		{
			return middle;
		}
		if (emp.emp_id[middle] < temp_id)
		{
			first = middle + 1;
		}
		if (emp.emp_id[middle] > temp_id)
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
		emp.pay[result] = emp.pay[result] + (emp.pay[result] * 0.05);
		cout << "\nUpdated successfully";
	}
}

void company::enqueue()
{
	
	int id=0;
	int result=0;
	cout << "\n\nEnter employee id ";
	id = validation();
	result = binarySearch(id);
	cout << result;
	if (-1 == result)
	{
		cout << "\n\nEmployee not found";
	}
	else
	{
		bench.push(id);
		cout << "\n\nEmployee moved to bench";

	}
	

}
void company::dequeue()
{
	if (!bench.empty())
	{
		cout << "\nEmployee id " << bench.front() << " moved to project";
		bench.pop();
	}
	else
	{
		cout << "\nThe bench is empty ";
	}
}
