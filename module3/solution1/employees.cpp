#include "employees.h"
#include<iostream>
#include<string>
using namespace std;

employees::employees()
{
}

　
employees::~employees()
{
}

void employees::setId(string id)
{
	employee_id = id;
}

void employees::setEmployeeName(string name)
{
	employee_name = name;
}
void employees::setDepartment(string dept)
{
	department = dept;
}
void employees::setProjectName(string project)
{
	project_name = project;
}
void employees::setYearOfJoining(int yoj)
{
	year_of_joining = yoj;
}
void employees::setPay(float salary)
{
	pay = salary;
}
