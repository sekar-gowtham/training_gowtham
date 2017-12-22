#include <string>
#include <vector>
//#include "Queue.h"
using namespace std;
#pragma once
class Request
{
private:
	//Queue queue;
	
	string air_id;
	string request_type;
public:
	void setRequest(string,string);
	void requestToQueue();

	Request();
	~Request();
};
