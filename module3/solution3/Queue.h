#include <string>
#include <vector>
#include <thread>
#include <iostream>
#include "Request.h"
using namespace std;
#pragma once
class Queue
{
private:

	vector<string> id;
	int count = 0;
	int front =0;														
	int rear = 0;
	
public:
	void setFront(int);
	int getFront();
	//void setRear(int);
	//int getRear();
	//void setCount(int);
	//int getCount();
	void displayQueue();
	void displayCount();
	void push(string);
	bool pop();
	
	void checkQueue();
	Queue();
	~Queue();
};

