#include <thread>
#include <iostream>
#include <ctime> 
#include "Airport.h"
using namespace std;

void main()
{
	Airport cbe;
	time_t total_time;
	total_time = time(NULL)+240;
	
	thread randomRequestGenerate(&Airport::generateRequest, &cbe,total_time);
	thread continuosCheckRunway1(&Airport::callCheckRunway1, &cbe,total_time);
	thread continuosCheckRunway2(&Airport::callCheckRunway2, &cbe,total_time);

	thread1.join();
	thread2.join();
	thread3.join();
	
	cin.get();
}


