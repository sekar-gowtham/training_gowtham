#ifndef empQueue_HEADER
#define empQueue_HEADER
#pragma once
#include<vector>
#include<iostream>

using namespace std;
class empQueue
{
public:
	
	empQueue();	
	~empQueue();
	int front=0;														//variable to store first element in queue
	int rear=0;															//variable to store last element  in queue
	vector<string> employee_id;											//variable to store employee id
	vector<string> department;											//variable to store department
	vector<string> project_name;										//variable to store project name
	vector<string> bench;												//variable to store employee id of bench employee
	void push();
	void pop();
	void viewBench();
	int binarySearch(string temp_id);
	void copyInfo(vector<string> id, vector<string> pro, vector<string> dept);
};
#endif
