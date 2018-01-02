#include <string>
#include <vector>
#include <iostream>
#include "Request.h"
using namespace std;
#pragma once
class Queue
{
private:
	vector<Request> reqst;
	int count = 0;
	int front =0;														
	int rear = 0;
public:
	int displayQueue();
	int calculateQueueSize();
	int getCount();
	void push(Request);
	Request pop();
	bool isEmpty();
	Queue();
	~Queue();
};

