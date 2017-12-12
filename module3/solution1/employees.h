#ifndef employees_HEADER
#define employees_HEADER
#pragma once

#include<vector>
#include<iostream>
using namespace std;
class employees
{
public:
	int id = 101;
	vector<string> employee_id;													//variable to store employee id
	vector<float> pay;															//variable to store pay
	vector<int> year_of_joining;												//variable to store year of joining 
	vector<string> employee_name;												//variable to store employee name
	vector<string> project_name;												//variable to store project name
	vector<string> department;													//variable to store department
	vector<string> bench;														//variable to store bench employees
	employees();
	~employees();
};

#endif
