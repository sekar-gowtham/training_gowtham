#include "company.h"
#include"empQueue.h"
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
	string project;
	string name;
	string dept;
	string temp;
	int year=0;
	int salary=0;
	temp = "EMP" + to_string(employee.id);						
	cout << "\nEmployee id " << temp << "\n";
	employee.employee_id.push_back(temp);													//auto generate id and push to employee_id variable
	employee.id++;
	cout << "\nEnter employee name ";
	cin >> name;
	employee.employee_name.push_back(name);													//get the name from user and push to employee_name variable

	cout << "\nEnter Project name ";
	cin >> project;
	employee.project_name.push_back(project);												//get the project name from the user and push to project_name variable

	cout << "\nEnter department ";
	cin >> dept;
	employee.department.push_back(dept);														//get the department from the user and puah to department variable

	while (year<1970||year > 2018)
	{
		cout << "\nEnter year of joining ";
		year = validation();															//reaptly get the year until user enter a valid year
	}
   	employee.year_of_joining.push_back(year);

	cout << "\nEnter Pay ";
	salary = validation();																//get the salary from the user and push to pay variable
	employee.pay.push_back(salary);
	queue.copyInfo(employee.employee_id, employee.project_name,employee.department);						
}

int company::validation()
{
	int error=0;
	int number=0;
	float floatnumber;
	do
	{
		error = 0;
		cin >> floatnumber;
		number = floatnumber;
		if (number < floatnumber)														//this condition will true when the user enters the float value
		{
			cout << "\nEnter valid integer ";
			error = 1;
		}
		else if (cin.fail())															//this condition will true when the user enters the string
		{
			cout << "\nPlease enter a integer" << endl;
			error = 1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	
	} while (1 == error);
		return number;
}

void company::displayDetails()															//display all the details of the user
{
	int iterate=0;
	for (iterate = 0; iterate < employee.employee_id.size(); iterate++)
	{
		cout << "\nEmployee id:\t " << employee.employee_id[iterate] ;
		cout <<"\nEmp Name:\t "<< employee.employee_name[iterate] ;
		cout <<"\nProject Name:\t "<< queue.project_name[iterate];
		cout <<"\nDepartment:\t "<< queue.department[iterate] ;
		cout <<"\nyear of joining: "<< employee.year_of_joining[iterate] ;
		cout <<"\nPay:\t\t "<< employee.pay[iterate] << "\n";
	}
}

void company::namesFromDateOfJoining()													//display particular names from date of joining
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

void company::employeeWithHighPay()														//employee details who got high pay from particular department
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

int company::binarySearch(string temp_id)
{
	
	int size=0;
	int first=0;
	int middle=0;
	int last=0;
	int id = 0;
	size = employee.employee_id.size();
	last = size-1;
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

void company::updatePay()																//update pay by 5% for particular employee 
{
	string temp_id;
	
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

　
/*

void company::push()
{
	string id;
	int flag = 0;
	int iterate = 0;
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
		for (iterate = front; iterate < rear; iterate++)
		{
			if (employee.bench[iterate] == id)
			{
				cout << "Employee already in bench";
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			employee.bench.push_back(id);
			cout << "\n\nEmployee moved to bench";
			employee.department.at(result) = "  ";
			employee.project_name.at(result) = "  ";
			rear++;
		}
	}
}
void company::pop()
{
	int index;
	string pro;
	string dept;
	string id;
	if (front==rear)
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
	if (front==rear)
	{
		cout << "\nbench is empty";
	}
	else
	{
		cout << "\nEmployees in bench\n";
		for (iterate = front; iterate < employee.bench.size(); iterate++)
		{
			cout << employee.bench[iterate] << endl;
		}
	}
}

*/
