/*
File name : main.cpp
Purpose : To store employee details
Author : Gowtham
*/
#include "employees.h"
#include "company.h"
#include<iostream>
using namespace std;
void main()
{

	company mt;
	int choice=0;
	while (1)
	{
		cout << "\n\n1.Add new employee\n2.Display names of employee from a particular year of joining\n3.details of the employee from a particular department having the highest pay";
		cout << "\n4.Display all details of all employees in ascending order\n5.Update pay by employee id ";
		cout << "\n6.Move Employee from project to bench\n7.Move Employee from bench to project\n8.View bench\n0.Exit";
		cout << "\nEnter choice ";
		choice = mt.getChoice();												//get the choice from the user
		
		switch (choice)														//execute case according to user's input
		{
		case 1:
			mt.createNewEmployee();											
			break;
		case 2:
			mt.namesFromDateOfJoining();
			break;
		case 3:
			mt.employeeWithHighPay();
			break;
		case 4:
			mt.displayDetails();
			break;
		case 5:
			mt.updatePay();
			break;
		case 6:
			mt.pushEmployee();
			break;
		case 7:
			mt.popEmployee();
			break;
		case 8:
			mt.viewBenchEmployee();
			break;
		case 0:
			exit(0);
		default:
			cout << "\nEnter valid choice ";
		}
	}																
}
