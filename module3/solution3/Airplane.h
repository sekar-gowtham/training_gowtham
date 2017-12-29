#include <string>
#include <iostream>
#include <ctime>
using namespace std;
#pragma once

class Airplane
{
private:
	string airplane_id;
public:
	string generateRequestType(string);
	string generateRequestId();
	void setAirplaneId(string);
	Airplane();
	~Airplane();
};

