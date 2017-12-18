#pragma once
#ifndef company_HEADER
#define company_HEADER

#include<iostream>
#include "employees.h"
#include "empQueue.h"
using namespace std;
class company
{
public:
	vector<employees> employee;
	employees *pointer;
	empQueue queue;
	
	company();
	~company();
	int id = 100;
	bool flag = 0;
	
	void createNewEmployee();
	void displayDetails();
	void namesFromDateOfJoining();
	void employeeWithHighPay();
	void updatePay();
	int binarySearch(string temp_id);
	int getChoice();
	int checkYear();
	float checkPay();
	void pushEmployee();
	void popEmployee();
	void viewBenchEmployee();
};

#endif
