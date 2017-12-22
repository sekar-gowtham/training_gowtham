#include <string>
#include <iostream>
#include <ctime>
#include "Request.h"
using namespace std;
#pragma once

class Airplane
{
private:
	Request request;

	string airplane_id;
	string airplane_company;
	
public:
	void generateRequest(string);
	void setAirplaneId(string);
	void setAirplaneCompany(string);
	/*string getAirplaneId();
	string getAirplaneCompany();*/
	Airplane();
	~Airplane();
};
