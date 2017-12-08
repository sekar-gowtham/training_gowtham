#pragma once
#ifndef company_HEADER
#define company_HEADER
#include<vector>
#include<iostream>
#include "employees.h"
#include "empQueue.h"
using namespace std;
class company
{
	
public:
	company();
	~company();
	employees  employee;
	
	int front = 0;
	int rear = 0;

	void createNewEmployee();
	void displayDetails();
	void namesFromDateOfJoining();
	void employeeWithHighPay();
	void updatePay();
	int binarySearch(int temp_id);
	int validation(void);
	void push();
	void pop();
	void viewBench();

　
};

#endif
