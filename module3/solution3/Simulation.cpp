/*
File name : Simulation.cpp
Purpose : to simulate activity at the airport
Author : Gowtham
*/

#include <thread>
#include <iostream>
#include <ctime> 
#include "Airport.h"
using namespace std;

void main()
{
	Airport cbe;
	time_t total_time;
	total_time = time(NULL) + 480;																	//set the total time for the simulation

	thread randomRequestGenerate(&Airport::callGenerateRequest, &cbe, total_time);					//create thread to generate the request at random
	thread continuosCheckRunway1(&Airport::callCheckRunway1, &cbe, total_time);						//create thread to check runway 1 continuosly
	thread continuosCheckRunway2(&Airport::callCheckRunway2, &cbe, total_time);						//create thread to check runway 2 continuosly

	randomRequestGenerate.join();
	continuosCheckRunway1.join();
	continuosCheckRunway2.join();

	cin.get();
}


