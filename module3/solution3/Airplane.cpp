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
void Airplane::setAirplaneCompany(string company)
{
	airplane_company = company;
	
}

void Airplane::generateRequest(string id)
{
	time_t end_time;
	int random_number;
	string req;
	

		random_number = rand() % 2;
			if (1 == random_number)
			{
				req = "landing";
			}
			else
			{
				req = "takeoff";
			}
		
	

	//request.setRequest(id, req);
	
}
