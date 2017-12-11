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
	cout << "\n\nEnter employee id ";
	cin >> id;
	result = binarySearch(id);															//search employee list whether the given id is present or not
	if (-1 == result)
	{
		cout << "\n\nEmployee not found";
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
			department.at(result) = "  ";
			project_name.at(result) = "  ";
			rear++;
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
		index = binarySearch(id);
		department[index] = dept;
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
size = employee_id.size();
last = size - 1;

while (first <= last)
{
	middle = (first + last) / 2;
	if (employee_id[middle] == temp_id)
	{
		return middle;
	}
	else if (employee_id[middle] < temp_id)
	{
		first = middle + 1;
	}
	else if (employee_id[middle] > temp_id)
	{
		last = middle - 1;
	}
}

return -1;
}
