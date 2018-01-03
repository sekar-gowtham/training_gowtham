#include <string>
#include <vector>
#include<ctime>

using namespace std;
#pragma once
class Request
{
private:
	string air_id;											//to store airplane id
	string request_id;										//to store request id
	string request_type;									//to store reuest type
	int in_time;											//to store in time of the request
public:
	void setAeroId(string);
	void setRequestId(string);
	void setRequestType(string);
	void setInTime(int);
	int getInTime();
	string getId();
	string getReqId();
	string getRequestType();
	Request();
	~Request();
};

