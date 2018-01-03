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
	Queue landingQueue;									//push the landing request to queue
	Queue takeoffQueue;									//push the takeoff request to queue
	Runway runway1, runway2;
	vector <Request> landed;
	vector <Request> tookoff;
	int id = 101;
	int time_taken = 120;								//time taken by airplane to landing or takeoff
	int time_interval = 60;
	int landing_waiting_time = 0;						//to store total landing waiting time
	int takeoff_waiting_time = 0;						//to store total takeoff waiting time
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

