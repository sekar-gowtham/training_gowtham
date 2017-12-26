#include <string>
#include <vector>

using namespace std;
#pragma once
class Request
{
private:

	
	string air_id;
	string request_type;
public:
	void setId(string);
	void setReq(string);
	string getId();
	string getReq();
	Request();
	~Request();
};

