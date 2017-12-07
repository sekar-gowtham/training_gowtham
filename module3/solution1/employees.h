#ifndef employees_HEADER
#define employees_HEADER
#pragma once

#include<vector>
#include<iostream>
using namespace std;
class employees
{
public:
	int id = 100;
	vector<int> emp_id;
	vector<int> pay;
	vector<int> year_of_joining;
	vector<string> emp_name;
	vector<string> department;
	
	

	employees();
	
	~employees();

};

#endif
