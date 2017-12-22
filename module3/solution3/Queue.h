#include <string>
#include <vector>
#include "Request.h"
using namespace std;
#pragma once
class Queue
{
private:

	vector<Request> landingQueue;
	vector<Request> takeoffQueue;
	
	int front = 0;														
	int rear = 0;
public:
	void setId(string);
	string getId();

	void push(string,string);
	void pop();
	void display();

	Queue();
	~Queue();
};
