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
	employees employee;
	empQueue queue;
	company();
	~company();
	int front = 0;
	int rear = 0;
	void createNewEmployee();
	void displayDetails();
	void namesFromDateOfJoining();
	void employeeWithHighPay();
	void updatePay();
	int binarySearch(string temp_id);
	int validation(void);
	/*void push();
	void pop();
	void viewBench();*/
};

#endif
