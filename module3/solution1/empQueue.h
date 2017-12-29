#ifndef empQueue_HEADER
#define empQueue_HEADER
#pragma once
#include <vector>
#include "employees.h"

using namespace std;
class empQueue
{
	vector <employees> bench;
	
public:
	
	empQueue();	
	~empQueue();
	int front=0;														//variable to store first element in queue
	int rear=0;															//variable to store last element  in queue	
	void push(string);
	string pop();
	void viewBench();
	
	
};


#endif