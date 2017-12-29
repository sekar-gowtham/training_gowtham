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
	
	id++;

	cout << "\nAdd Employee ";
	temp = "EMP" + to_string(id);						
	cout << "\nEmployee id " << temp ;
	employ.setId(temp);														//auto generate id and assign to pointer object

	cout << "\nEnter employee name ";
	cin.ignore();
	getline(cin, name);
	employ.setEmployeeName(name);												//get the name from user and assign to object object

	cout << "\nEnter Project name ";
	getline(cin, project);
	employ.setProjectName(project);											//get the project name and assign to pointer object

	cout << "\nEnter department ";
	getline(cin, dept);
	employ.setDepartment(dept);												//get the department name and assign to pointer object

	cout << "\nEnter year of joining ";
	year = checkYear();																	
	employ.setYearOfJoining(year);											//get the year and assign to pointer object
   
	cout << "\nEnter Pay ";
	salary = checkPay();																	
	employ.setPay(salary);													//get the salary and assign to pointer object

	employee.push_back(employ);												//push the pointer object to employee object
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
		int it;
		for (it = 0; it < employee.size(); ++it)
		{
			cout << "\n\nEmployee id:\t " << employee[it].getId();									//display employee id
			cout << "\nEmp Name:\t " << employee[it].getEmployeeName();									//display employee name
			cout << "\nProject Name:\t " << employee[it].getProjectName();								//display employee's project name
			cout << "\nDepartment:\t " << employee[it].getDepartment();									//display employee's department
			cout << "\nyear of joining: " << employee[it].getYearOfJoining();							//display date of joining
			cout << "\nPay:\t\t " << employee[it].getpay();												//display employee's pay
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
		int it;
		for (it = 0; it < employee.size(); ++it)
		{
			if (employee[it].getYearOfJoining() == doj)
			{
				f = 1;
				cout << "\n" << employee[it].getEmployeeName();
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

		int it;
		int t;
		for (it = 0; it < employee.size(); ++it)
		{
			if (employee[it].getDepartment() == dept)										//compare given department with the list
			{
				f = 1;
				if (amount < employee[it].getpay() )
				{
					amount = employee[it].getpay();
					t = it;
				}

			}
		}
		if (1 == f)
		{
			cout << "\nhighest Pay in " << dept << " department";							//display details of that particular employee
			cout << "\nEmployee id " << employee[t].getId();
			cout << "\nEmployee name " << employee[t].getEmployeeName();
			cout << "\nProject name " << employee[t].getProjectName();
			cout << "\nYear of joining " << employee[t].getYearOfJoining();
			cout << "\nPay " << employee[t].getpay();
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
	float pay;
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
			pay = employee[result].getpay() + (employee[result].getpay() * 0.05);	//update pay by 5%
			employee[result].setPay(pay);
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
		if (employee[middle].getId() == temp_id)										//compare the middle element with given id 
		{
			return middle;																	//return index if middle element is equal to given id
		}
		else if (employee[middle].getId() < temp_id)
		{
			first = middle + 1;																//change first value if middle element is less than given id
		}
		else if (employee[middle].getId() > temp_id)
		{
			last = middle - 1;																//change last value if middle element is greater than given id
		}
	}
	return -1;
}

void company::addEmployeeToBench()
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
			employee[result].setDepartment("");
			employee[result].setProjectName("");
		}
	}
}

void company::addEmployeeToProject()
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
		employee[index].setDepartment( dept);
		employee[index].setProjectName(project);
	}
}

void company::viewBenchEmployee()
{
	queue.viewBench();
}