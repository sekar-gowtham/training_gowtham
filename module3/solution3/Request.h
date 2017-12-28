#include <string>
#include <vector>
#include<ctime>

using namespace std;
#pragma once
class Request
{
private:
	string air_id;
	string request_id;
	string request_type;
	time_t in_time;
public:
	void setId(string);
	void setRequestId(string);
	void setRequestType(string);
	void setInTime(time_t);
	time_t getInTime();
	int calculatesize();
	string getId();
	string getReqId();
	string getRequestType();
	Request();
	~Request();
};

