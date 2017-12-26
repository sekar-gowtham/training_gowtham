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
//void Airplane::setAirplaneCompany(string company)
//{
//	airplane_company = company;
//	
//}

string Airplane::generateRequest(string id)
{
	int random_number;
	string reqt;
	

		random_number = rand() % 2;
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