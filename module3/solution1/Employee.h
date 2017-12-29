#pragma once
#include<iostream>
#include<string>
using namespace std;
class Employee
{
private:
	string empname;
	int ID;
	int salary;
	int joining_year;
public:
	void getdata()
	{
		cout << "Enter name,id and salary";
		cin >> empname;
		cin >> ID;
		cin >> salary;
	}
	void display()
	{
		cout << empname;
		cout << ID;
		cout << salary;
	}
};

