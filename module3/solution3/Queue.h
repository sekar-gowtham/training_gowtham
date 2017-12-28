#include <string>
#include <vector>
#include <iostream>
#include "Request.h"
using namespace std;
#pragma once
class Queue
{
private:
	vector<string> airplane_id;
	vector<string> req_id;
	int count = 0;
	int front =0;														
	int rear = 0;
public:
	void displayQueue();
	void displayCount();
	void push(string,string);
	bool pop();
	string getPopId();
	Queue();
	~Queue();
};

