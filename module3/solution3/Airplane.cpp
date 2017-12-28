#include "Airplane.h"

Airplane::Airplane()
{
}

Airplane::~Airplane()
{
}

void Airplane::setAirplaneId(string id)
{
	airplane_id = id;
}

void Airplane::setRequestId(string rid)
{
	req_id = rid;
}



string Airplane::generateRequestType(string id)
{
	int random_number;
	string reqt;
		random_number  = rand() % 2;

			if (1 == random_number)
			{
				reqt = "landing";
			}
			else
			{
				reqt = "takeoff";
			}
			cout << "\n" << reqt << " request created " << endl;
			return reqt;
}

string Airplane::generateRequestId()
{
	static int reqid = 151;
	string rid;
	reqid++;
	rid = "REQ" + to_string(reqid);
	
	return rid;
}