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

	vector<Request> landingQueue;
	vector<Request> takeoffQueue;
	
	int landing_count = 0;
	int takeoff_count = 0;
	int landing_front = 0;														
	int landing_rear = 0;
	int takeoff_front = 0;
	int takeoff_rear = 0;
public:
	void displayQueue();
	void landingTakeoffCount();
	void push(string,string);
	bool pop();
	
	void checkQueue();
	Queue();
	~Queue();
};
