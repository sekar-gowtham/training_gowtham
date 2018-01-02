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
	vector <Request> landed;
	vector <Request> tookoff;
	int id=101;
	int time_taken = 60;
	int landing_time=0;
	int takeoff_time=0;
	
public:
	string genarateAirId();
	void generateRequest();
	void callGenerateRequest(time_t t);
	void callCheckRunway1(time_t t);
	void callCheckRunway2(time_t t);
	void checkRunway1(time_t t);
	void checkRunway2(time_t t);
	Airport();
	~Airport();
};

