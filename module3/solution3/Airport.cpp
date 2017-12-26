#include "Airport.h"


Airport::Airport()
{
	runway1.setStatus(0);
	runway2.setStatus(0);
}


Airport::~Airport()
{
}

string Airport::genarateAirId()
{
	string aid;

	int random_number;
	time_t end_time;
	
	//srand(time(NULL));


	random_number = rand() % 60;
	end_time = time(NULL) + random_number;
	while (1)
	{
		if (time(NULL) == end_time)
		{
			aid = "AID" + to_string(id);
			id++;
			

			airobj.setAirplaneId(aid);
			
			airways.push_back(airobj);
			break;
		}
	}
	
	return aid;
	
}
void Airport::firstOperation(time_t t)
{
	
	aero_id = genarateAirId();

	req = airobj.generateRequest(aero_id);

	queue.push(aero_id, req);

	thread thread2(&Airport::checkRunway1,this);
	thread thread3(&Airport::checkRunway2, this);
	if (time(NULL) < t)
	{
		firstOperation(t);
	}
}

void Airport::checkRunway1()
{
	bool check;
	time_t end_time;
	if (runway1.getStatus() == 0)
	{
		runway1.setStatus(1);
		check=queue.pop();
		if (1 == check)
		{
			end_time = time(NULL) + 60;
			while (1)
			{
				if (time(NULL) == end_time)
				{

					break;
				}
			}
		}
		runway1.setStatus(0);
	}
}

void Airport::checkRunway2()
{
	bool check;
	time_t end_time;
	if (runway2.getStatus() == 0)
	{
		runway2.setStatus(1);
		check=queue.pop();
		if (1 == check)
		{
			end_time = time(NULL) + 60;
			while (1)
			{
				if (time(NULL) == end_time)
				{

					break;
				}
			}
		}
		runway2.setStatus(0);
	}
}

void Airport::display()
{
	queue.landingTakeoffCount();
	queue.displayQueue();
}

