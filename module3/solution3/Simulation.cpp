#include <thread>
#include <iostream>
#include <ctime> 
#include "Airport.h"
using namespace std;

void main()
{
	Airport cbe;
	time_t total_time;
	total_time = time(NULL)+7200;
	
	thread thread1(&Airport::operation1, &cbe,total_time);
	thread thread2(&Airport::operation2, &cbe,total_time);
	thread thread3(&Airport::operation3, &cbe,total_time);

	thread1.join();
	thread2.join();
	thread3.join();
	
	cin.get();
}


