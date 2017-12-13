#include "empQueue.h"
#include "company.h"
#include "employee.h"
#include<vector>
#include<iostream>

　
empQueue::empQueue()
{
	
}

　
empQueue::~empQueue()
{
}

void empQueue::copyInfo(vector<string> id,vector<string> pro, vector<string> dept)		//get copy of employee id, project name, department from employee class
{
	employee_id.swap(id);
	department.swap(dept);
	project_name.swap(pro);
}

void empQueue::push()																    //remove employee from project to bench			
{
	string id;
	int flag = 0;
	int iterate = 0;
	int result = 0;
	if (employee_id.size() == 0)
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
			for (iterate = front; iterate < rear; iterate++)								//search bench whether the employee is already in bench or not
			{
				if (bench[iterate] == id)
				{
					cout << "Employee already in bench";
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				bench.push_back(id);														//push the employee to the bench
				cout << "\n\nEmployee moved to bench";
				department.at(result) = "  ";												//remove the department name and project name for particular employee
				project_name.at(result) = "  ";
				rear++;
			}
		}
	}
}

void empQueue::pop()
{
	int index;
	string pro;
	string dept;
	string id;
	if (front == rear)																	//check whether the bench is empty or not
	{
		cout << "\nbench is empty";
	}
	else
	{
		cout << "\nEnter project name ";												//get department and project name from user and move to project
		cin >> pro;
		cout << "\nEnter department ";
		cin >> dept;
		id = bench[front];
		index = binarySearch(id);														//search employee list whether the given id is present or not
		department[index] = dept;														//assign department name and project name to particular employee
		project_name[index] = pro;
		cout << "\nEmployee " << id << " moved to project";
		front++;
	}
}
void empQueue::viewBench()
{
	int iterate = 0;
	if (front == rear)																	//check whether the bench is empty or not
	{
		cout << "\nbench is empty";
	}
	else
	{
		cout << "\nEmployees in bench\n\n";
		for (iterate = front; iterate < bench.size(); iterate++)						//display employee id from bench
		{
			cout << bench[iterate] << endl;
		}
	}
}

int empQueue::binarySearch(string temp_id)
{
int size = 0;
int first = 0;
int middle = 0;
int last = 0;
int id = 0;
size = employee_id.size();																//calculate number of employees
last = size - 1;

while (first <= last)
{
	middle = (first + last) / 2;
	if (employee_id[middle] == temp_id)													//compare the middle element with given id 
	{
		return middle;																	//return index if middle element is equal to given id
	}
	else if (employee_id[middle] < temp_id)
	{
		first = middle + 1;																//change first value if middle element is less than given id
	}
	else if (employee_id[middle] > temp_id)
	{
		last = middle - 1;																//change last value if middle element is greater than given id
	}
}

return -1;
}
