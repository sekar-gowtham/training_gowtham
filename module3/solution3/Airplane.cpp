#include "Airplane.h"

Airplane::Airplane()
{
}

Airplane::~Airplane()
{
}



string Airplane::generateRequestType(string id)
{
	int random_number;
	string reqt;
	time_t t;
	time(&t);
	struct tm info;
	localtime_s(&info, &t);
	random_number = rand() % 2;

	if (1 == random_number)
	{
		reqt = "landing";
	}
	else
	{
		reqt = "takeoff";
	}
	cout <<reqt << " request created " << info.tm_hour << " : " << info.tm_min << " : " << info.tm_sec << endl;
	return reqt;
}

string Airplane::generateRequestId()
{
	static int reqid = 151;
	string request_id;
	reqid++;
	request_id = "REQ" + to_string(reqid);
	cout << "\nRequest id " << request_id<<" with ";
	return request_id;
}
