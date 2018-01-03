#include <string>
#include <iostream>
#include <ctime>
using namespace std;
#pragma once

class Airplane
{
public:
	string generateRequestType(string);
	string generateRequestId();
	Airplane();
	~Airplane();
};

