#include <string>
#include<vector>
#include<ctime>
#include<thread>
#include "Queue.h"
#include "Airplane.h"
#include "Runway.h"

using namespace std;
#pragma once
class Airport
{
private:
	Queue queue;
	vector <Airplane> airways;
	Runway runway1, runway2;
	Airplane airobj;
	int id=101;
	string aero_id;
	string req;
public:
	void display();
	string genarateAirId();
	void firstOperation(time_t t);
	void checkRunway1();
	void checkRunway2();
	Airport();
	~Airport();

};

