#include <string>
#include<vector>
#include<ctime>
#include<chrono>
#include<thread>
#include "Queue.h"
#include "Airplane.h"
#include "Runway.h"

using namespace std;
#pragma once
class Airport
{
private:
	Queue landingQueue;
	Queue takeoffQueue;
	vector <Airplane> airways;
	Runway runway1, runway2;
	vector <Request> landing;
	vector <Request> takeoff;
	int id=101;
	int time_taken = 900;
	int landing_time=0;
	int takeoff_time=0;
	
public:
	string genarateAirId();
	void startOperation();
	void operation1(time_t t);
	void operation2(time_t t);
	void operation3(time_t t);
	void checkRunway1(time_t t);
	void checkRunway2(time_t t);
	Airport();
	~Airport();
};

