#pragma once
#include "employees.h"
#include "company.h"

using namespace std;
class empQueue
{
public:
	company mt;
	employees emp;
	int front;
	int rear;
	vector<int> bench;
	void projectToBench();
	void benchToProject();
	void viewBench();
	int binarySearch(int temp_id);
	empQueue();
	~empQueue();

};
