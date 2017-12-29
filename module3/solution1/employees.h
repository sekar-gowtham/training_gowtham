#ifndef employees_HEADER
#define employees_HEADER
#pragma once

#include<vector>
#include<iostream>
#include<string>

using namespace std;
class employees
{
private:
	string employee_id;													//variable to store employee id
	float pay;															//variable to store pay
	int year_of_joining;												//variable to store year of joining 
	string employee_name;												//variable to store employee name
	string project_name;												//variable to store project name
	string department;													//variable to store department
public:


	void setId(string id);
	string getId();
	void setPay(float tpay);
	float getpay();
	void setYearOfJoining(int yoj);
	int getYearOfJoining();
	void setEmployeeName(string name);
	string getEmployeeName();
	void setProjectName(string project);
	string getProjectName();
	void setDepartment(string dept);
	string getDepartment();
	
	employees();
	~employees();
};

#endif