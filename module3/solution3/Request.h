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
	int in_time;
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

