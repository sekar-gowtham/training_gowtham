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
	float salary=0;
	cout << "\nAdd Employee ";
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
	employee.department.push_back(dept);													//get the department from the user and puah to department variable
														
	cout << "\nEnter year of joining ";
	year = checkYear();																	
	
   	employee.year_of_joining.push_back(year);

	cout << "\nEnter Pay ";
	salary = checkPay();																	//get the salary from the user and push to pay variable
	employee.pay.push_back(salary);
	queue.copyInfo(employee.employee_id, employee.project_name,employee.department);		//pass the employee id ,project name ,department to the queue
}

int company::checkYear()
{
	float floatnumber;
	int year;
	int error = 0;
	do
	{
		error = 0;

		cin >> floatnumber;
		year = floatnumber;
		if (cin.fail())																		// this condition will true when the user enters the string
		{
			cout << "\nPlease enter a year" << endl;
			error = 1;
			cin.clear();																	//clearing the error flags of cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');							//ignore the wrong input
		}
		else if (year < floatnumber)														//this condition will true when the user enters the float value
		{
			cout << "\nEnter valid year ";
			error = 1;
		}
		else if (year < 1970 || year > 2017)												//reaptly get the year until user enter between the range
		{
			cout << "\n Enter year between 1970 - 2017 ";
			error = 1;
		}

	} while (1 == error);
	return year;
}

float company::checkPay()
{
	int error=0;
	
	float pay;
	do
	{
		error = 0;
		cin >> pay;
		
		if (cin.fail())																		//this condition will true when the user enters the string
		{
			cout << "\nPlease enter a Pay" << endl;
			error = 1;
			cin.clear();																	//clearing the error flags of cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');							//ignore the wrong input
		}
	
	} while (1 == error);
return pay;
}

void company::displayDetails()																//display all the details of the user
{
	int iterate=0;
	
		for (iterate = 0; iterate < employee.employee_id.size(); iterate++)
		{
			cout << "\nEmployee id:\t " << employee.employee_id[iterate];					//display employee id
			cout << "\nEmp Name:\t " << employee.employee_name[iterate];					//display employee name
			cout << "\nProject Name:\t " << queue.project_name[iterate];					//display employee's project name
			cout << "\nDepartment:\t " << queue.department[iterate];						//display employee's department
			cout << "\nyear of joining: " << employee.year_of_joining[iterate];				//display date of joining
			cout << "\nPay:\t\t " << employee.pay[iterate] << "\n";							//display employee's pay
		}
	
}

void company::namesFromDateOfJoining()													//display particular names from date of joining
{
	int doj=0;
	int iterate = 0;
	int flag=0;
	cout << "\nEnter year of joining ";
	doj = checkYear();
	for (iterate = 0; iterate < employee.employee_id.size(); iterate++)
	{
		if (employee.year_of_joining[iterate] == doj)									//compare given date of joining with the list
		{
			flag = 1;
			cout << "\n" << employee.employee_name[iterate];							//display employee name when the given date of joining is match
		}
	}
	if (0 == flag)																		//inform the user that there is no employee with given date of joining
	{
		cout << "\nThere is no employee with given year of joining";
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
		if (employee.department[iterate] == dept)										//compare given department with the list
		{
			flag = 1;
			if (amount < employee.pay[iterate])											
			{
				high = iterate;															//copy the index value when high pay is come
			}
		}
	}
	if (1 == flag)
	{
		cout << "\nhighest Pay in " << dept << " department";							//display details of that particular employee
		cout << "\nEmployee id " << employee.employee_id[high];
		cout << "\nEmployee name " << employee.employee_name[high];
		cout << "\nProject name " << employee.project_name[high];
		cout << "\nYear of joining " << employee.year_of_joining[high];
		cout << "\nPay " << employee.pay[high];
	}
	else
	{
		cout << "\ndepartment not match ";												//inform the user that no match of given department 
	}
}

　
void company::updatePay()																//update pay by 5% for particular employee 
{
	string temp_id;
	
	int result=0;
	cout << "\n\nEnter employee id ";
	cin >> temp_id;
	result = queue.binarySearch(temp_id);														//search employee list whether the given id is present or not
	if (-1 == result)
	{
		if (temp_id.compare(0, 3, "EMP") == 0)											//check whether the given id is valid or not
		{
			cout << "\nThere is no employee with id " << temp_id;
		}
		else
		{
			cout << "\n\nInvalid Employee id ";
		}
	}
	else
	{
		employee.pay[result] = employee.pay[result] + (employee.pay[result] * 0.05);	//update pay by 5%
		cout << "\nUpdated successfully";
	}
}

int company::getChoice()
{
	float floatnumber;
	int choice;
	int error = 0;
	do
	{
		error = 0;

		cin >> floatnumber;
		choice = floatnumber;
		if (cin.fail())																			//this condition will true when the user enters the string
		{
			cout << "\nPlease enter the choice" << endl;
			error = 1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (choice < floatnumber)															//this condition will true when the user enters the float value
		{
			cout << "\nEnter valid choice ";
			error = 1;
		}
	} while (1 == error);
	return choice;
}
