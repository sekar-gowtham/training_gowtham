#ifndef company_HEADER
#define company_HEADER
#pragma once
#include<vector>
#include<queue>
#include<iostream>
#include"employees.h"
using namespace std;
class company
{
	
public:
	employees  emp;
	queue<int> bench;
	company();
	~company();
	void createNewEmployee();
	void displayDetails();
	void namesFromDateOfJoining();
	void employeeWithHighPay();
	void updatePay();
	int binarySearch(int temp_id);
	int validation();
	void enqueue();
	void dequeue();

　
};

#endif
