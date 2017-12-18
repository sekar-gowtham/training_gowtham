#ifndef employees_HEADER
#define employees_HEADER
#pragma once

#include<vector>
#include<iostream>
#include<string>

using namespace std;
class employees
{
public:
	
	string employee_id;													//variable to store employee id
	float pay;															//variable to store pay
	int year_of_joining;												//variable to store year of joining 
	string employee_name;												//variable to store employee name
	string project_name;												//variable to store project name
	string department;													//variable to store department
	
	void setId(string id);
	void setPay(float tpay);
	void setYearOfJoining(int yoj);
	void setEmployeeName(string name);
	void setProjectName(string project);
	void setDepartment(string dept);

	
	employees();
	~employees();
};

#endif
