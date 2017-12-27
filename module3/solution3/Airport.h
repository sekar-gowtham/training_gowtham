#include <string>
#include<vector>
#include<ctime>
#include<thread>
#include "Queue.h"
#include "Airplane.h"
#include "Runway.h"
#include<chrono>
using namespace std;
#pragma once
class Airport
{
private:
	Queue landingQueue;
	Queue takeoffQueue;
	vector <Airplane> airways;
	Runway runway1, runway2;
	Airplane airobj;
	
	int id=101;
	string aero_id;
	string req;
public:
	
	string genarateAirId();
	void startOperation();
	void operation1(time_t t);
	void operation2(time_t t);
	void operation3(time_t t);
	void checkRunway1();
	void checkRunway2();
	Airport();
	~Airport();

};

