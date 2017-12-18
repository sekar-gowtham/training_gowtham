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
	flag = 1;
	pointer = new employees;
	id++;

	cout << "\nAdd Employee ";
	temp = "EMP" + to_string(id);						
	cout << "\nEmployee id " << temp ;
	pointer->setId(temp);														//auto generate id and assign to pointer object

	cout << "\nEnter employee name ";
	cin.ignore();
	getline(cin, name);
	pointer->setEmployeeName(name);												//get the name from user and assign to object object

	cout << "\nEnter Project name ";
	getline(cin, project);
	pointer->setProjectName(project);											//get the project name and assign to pointer object

	cout << "\nEnter department ";
	getline(cin, dept);
	pointer->setDepartment(dept);												//get the department name and assign to pointer object

	cout << "\nEnter year of joining ";
	year = checkYear();																	
	pointer->setYearOfJoining(year);											//get the year and assign to pointer object
   
	cout << "\nEnter Pay ";
	salary = checkPay();																	
	pointer->setPay(salary);													//get the salary and assign to pointer object

	employee.push_back(*pointer);												//push the pointer object to employee object
	cout << "\nEmployee added successfully ";
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
		else if ((year < floatnumber) ||( year < 1970))														//this condition will true when the user enters the float value
		{
			cout << "\nEnter valid year ";
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
	if (flag == 0)
	{
		cout << "\nThere is no employee in company , create employee first ";
	}
	else
	{
		vector<employees>::iterator it;
		for (it = employee.begin(); it != employee.end(); ++it)
		{
			cout << "\n\nEmployee id:\t " << it->employee_id;									//display employee id
			cout << "\nEmp Name:\t " << it->employee_name;									//display employee name
			cout << "\nProject Name:\t " << it->project_name;								//display employee's project name
			cout << "\nDepartment:\t " << it->department;									//display employee's department
			cout << "\nyear of joining: " << it->year_of_joining;							//display date of joining
			cout << "\nPay:\t\t " << it->pay;												//display employee's pay
		}
	}
}

void company::namesFromDateOfJoining()													//display particular names from date of joining
{
	int doj=0;
	int iterate = 0;
	int f=0;
	
	if (flag == 0)
	{
		cout << "\nThere is no employee in company , create employee first ";
	}
	else
	{
		cout << "\nEnter year of joining ";
		doj = checkYear();
		vector<employees>::iterator it;
		for (it = employee.begin(); it != employee.end(); ++it)
		{
			if (it->year_of_joining == doj)
			{
				f = 1;
				cout <<"\n"<< it->employee_name;
			}
		}
		if (0 == f)																		//inform the user that there is no employee with given date of joining
		{
			cout << "\nThere is no employee with given year of joining";
		}
	}
}

void company::employeeWithHighPay()														//employee details who got high pay from particular department
{
	
	int high = 0;
	int amount = 0;
	string dept;
	int f = 0;
	if (0==flag)
	{
		cout << "\nThere is no employee in company , create employee first ";
	}
	else
	{
		cout << "\nEnter department ";
		cin >> dept;

		vector<employees>::iterator it;
		vector<employees>::iterator t;
		for (it = employee.begin(); it != employee.end(); ++it)
		{
			if (it->department == dept)										//compare given department with the list
			{
				f = 1;
				if (amount < it->pay)
				{
					amount = it->pay;
					t = it;
				}

			}
		}
		if (1 == f)
		{
			cout << "\nhighest Pay in " << dept << " department";							//display details of that particular employee
			cout << "\nEmployee id " << t->employee_id;
			cout << "\nEmployee name " << t->employee_name;
			cout << "\nProject name " << t->project_name;
			cout << "\nYear of joining " << t->year_of_joining;
			cout << "\nPay " <<t->pay;
		}
		else
		{
			cout << "\ndepartment not match ";												//inform the user that no match of given department 
		}
	}
}

　
void company::updatePay()																//update pay by 5% for particular employee 
{
	string temp_id;
	
	int result=0;
	if (flag == 0)
	{
		cout << "\nThere is no employee in company , create employee first ";
	}
	else
	{

		cout << "\n\nEnter employee id ";
		cin >> temp_id;
		result = binarySearch(temp_id);														//search employee list whether the given id is present or not
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
			employee[result].pay = employee[result].pay + (employee[result].pay * 0.05);	//update pay by 5%
			cout << "\nUpdated successfully";
		}
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

int company::binarySearch(string temp_id)
{
	int size = 0;
	int first = 0;
	int middle = 0;
	int last = 0;
	size = employee.size();
	last = size - 1;
	middle = (first + last) / 2;
																	
	

　
	while (first <= last)
	{
		middle = (first+last) / 2;
		if (employee[middle].employee_id == temp_id)										//compare the middle element with given id 
		{
			return middle;																	//return index if middle element is equal to given id
		}
		else if (employee[middle].employee_id < temp_id)
		{
			first = middle + 1;																//change first value if middle element is less than given id
		}
		else if (employee[middle].employee_id > temp_id)
		{
			last = middle - 1;																//change last value if middle element is greater than given id
		}
	}

	return -1;
}

void company::pushEmployee()
{
	string id;
	int result = 0;
	if (flag == 0)
	{
		cout << "\nThere is no employee in company , create employee first ";
	}
	else
	{
		cout << "\n\nEnter employee id ";
		cin >> id;
		result = binarySearch(id);															//search employee list whether the given id is present or not
		if (-1 == result)
		{
			if (id.compare(0, 3, "EMP") == 0)												//check whether the given id is valid or not
			{
				cout << "\nThere is no employee with id " << id;
			}
			else
			{
				cout << "\n\nInvalid Employee id ";
			}
		}
		else
		{
			queue.push(id);
			employee[result].department = "";
			employee[result].project_name = "";
		}
	}
}

void company::popEmployee()
{
	int index = 0;
	string id;
	string project;
	string dept;
	id = queue.pop();
	if (id != "abc")
	{
		index = binarySearch(id);	
		cout << "\nEnter project name ";
		cin >> project;																		//get the new project name from user
		cout << "\nEnter department name ";
		cin >> dept;																		//get the new department name from the user
		employee[index].department = dept;
		employee[index].project_name = project;
	}
}

void company::viewBenchEmployee()
{
	queue.viewBench();
}
