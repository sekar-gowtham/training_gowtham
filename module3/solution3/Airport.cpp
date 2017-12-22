#include "Airport.h"

　
Airport::Airport()
{
	
}

　
Airport::~Airport()
{
}

string Airport::genarateAirId()
{
	string aid;
	string company;
	int random_number;
	time_t end_time;
	string req;
	srand(time(NULL));

　
	random_number = rand() % 180;
	end_time = time(NULL) + random_number;
	while (1)
	{
		if (time(NULL) == end_time)
		{
			aid = "AID" + to_string(id);
			id++;
			

			airobj.setAirplaneId(aid);
			/*airobj.setAirplaneCompany(company);*/
			airways.push_back(airobj);
		}
	}
	
	return aid;
	//airobj.generateRequest(aid);
}
