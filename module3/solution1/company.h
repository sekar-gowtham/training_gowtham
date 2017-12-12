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
	int front = 0;												//to identify first element in the bench
	int rear = 0;												//to identify last element in the bench
	void createNewEmployee();
	void displayDetails();
	void namesFromDateOfJoining();
	void employeeWithHighPay();
	void updatePay();
	int binarySearch(string temp_id);
	int getChoice();
	int checkYear();
	float checkPay();

};

#endif
