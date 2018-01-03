#include <string>
#include <vector>
#include <iostream>
#include "Request.h"
using namespace std;
#pragma once
class Queue
{
private:
	vector<Request> request;							//to store the request in the queue
	int count = 0;										//to maintain the number of landing and takeoff performed
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

