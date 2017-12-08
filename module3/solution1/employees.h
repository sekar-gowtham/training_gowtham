#ifndef employees_HEADER
#define employees_HEADER
#pragma once

#include<vector>
#include<iostream>
using namespace std;
class employees
{
public:
	//empQueue q;
	int id = 100;

	vector<int> employee_id;
	vector<int> pay;
	vector<int> year_of_joining;
	vector<string> employee_name;
	vector<string> project_name;
	vector<string> department;
	vector <int> bench;
	

	employees();
	
	~employees();

};

#endif
