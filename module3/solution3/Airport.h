#include <string>
#include<vector>
#include<ctime>
#include "Airplane.h"
#include "Runway.h"

using namespace std;
#pragma once
class Airport
{
private:
	
	vector <Airplane> airways;
	Runway runway1, runway2;
	int id=101;
public:
	Airplane airobj;
	string genarateAirId();
	Airport();
	~Airport();

};
