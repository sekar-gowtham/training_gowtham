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

string employees::getId()
{
	return employee_id;
}

void employees::setEmployeeName(string name)
{
	employee_name = name;
}

string employees::getEmployeeName()
{
	return employee_name;
}

void employees::setDepartment(string dept)
{
	department = dept;
}

string employees::getDepartment()
{
	return department;
}

void employees::setProjectName(string project)
{
	project_name = project;
}

string employees::getProjectName()
{
	return project_name;
}

void employees::setYearOfJoining(int yoj)
{
	year_of_joining = yoj;
}

int employees::getYearOfJoining()
{
	return year_of_joining;
}

void employees::setPay(float salary)
{
	pay = salary;
}

float employees::getpay()
{
	return pay;
}