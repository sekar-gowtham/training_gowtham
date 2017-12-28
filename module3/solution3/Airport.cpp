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
	Airplane airobj;

	/*aid = "AID" + to_string(id);
	id++;
	airobj.setAirplaneId(aid);
	airways.push_back(airobj);*/

	int random_number;
	time_t end_time;
	random_number = rand() % 50;
	end_time = time(NULL) + random_number;
	while (1)
	{
		if (time(NULL) > end_time)
		{
			aid = "AID" + to_string(id);
			id++;
			
			break;
		}
	}
	return aid;
}

void Airport::startOperation()
{
	Airplane airobj;
	string req;
	string rid;
	Request r;
	time_t t;
	aero_id = genarateAirId();
	airobj.setAirplaneId(aero_id);
	rid = airobj.generateRequestId();
	airobj.setRequestId(rid);
	airways.push_back(airobj);


	req = airobj.generateRequestType(aero_id);
	r.setId(aero_id);
	r.setRequestId(rid);
	r.setRequestType(req);
	t = time(NULL);
	r.setInTime(t);
	request.push_back(r);

	if (req == "landing")
	{
		landingQueue.push(aero_id,rid);
	}
	else
	{
		takeoffQueue.push(aero_id,rid);
	}		
}

void Airport::checkRunway1()
{

	/*bool check1 = 0;
	if (runway1.getStatus() == 0)
	{
		runway1.setStatus(1);
		check1 = landingQueue.pop();
		if (1 == check1)
		{
			cout << "\nlanding performed";
		}
		else
		{
			check1 = takeoffQueue.pop();

			if (1 == check1)
			{
				cout << "\ntakeoff performed";
			}
		}
		runway1.setStatus(0);
	}*/
	string popId;
	bool check=0;
	time_t t4;
	time_t t5;
	if (runway1.getStatus() == 0)
	{
		runway1.setStatus(1);
		popId = landingQueue.getPopId();
		check=landingQueue.pop();
		if (check)
		{
			for (int i = 0; i < request.size(); i++)
			{
				if (popId == request[i].getId())
				{
					t4 = request[i].getInTime();
					t5 = time(NULL);
					landing_time = landing_time + (t5 - t4);
					break;
				}
			}
			
			this_thread::sleep_for(chrono::seconds(30));
		}
		else
		{
			popId = takeoffQueue.getPopId();
			check = takeoffQueue.pop();
			if ( check)
			{
				for (int i = 0; i < request.size(); i++)
				{
					if (popId == request[i].getId())
					{
						t4 = request[i].getInTime();
						t5 = time(NULL);
						takeoff_time = takeoff_time + (t5 - t4);
						break;
					}
				}
				this_thread::sleep_for(chrono::seconds(30));
			}
		}
		runway1.setStatus(0);
	}
}

void Airport::checkRunway2()
{
	string popId;
	time_t t4;
	time_t t5;
	/*bool check1 = 0;
	if (runway2.getStatus() == 0)
	{
		runway2.setStatus(1);
		check1 = landingQueue.pop();
		if (1 == check1)
		{
			cout << "\nlanding performed";
		}
		else
		{
			check1 = takeoffQueue.pop();

			if (1 == check1)
			{
				cout << "\ntakeoff performed";
			}
		}
		runway2.setStatus(0);
	}*/
	bool check1=0;
	
	if (runway2.getStatus() == 0)
	{
		runway2.setStatus(1);
		popId = landingQueue.getPopId();
		check1 = landingQueue.pop();
		
		if (check1)
		{
			
			
			for (int i = 0; i <request.size(); i++)
			{
				if (popId == request[i].getId())
				{
					t4 = request[i].getInTime();
					t5 = time(NULL);
					landing_time = landing_time + (t5 - t4);
					break;
				}
			}
			this_thread::sleep_for(chrono::seconds(30));
		}
		else
		{
			popId = takeoffQueue.getPopId();
			check1 = takeoffQueue.pop();
			
			if (check1)
			{
				for (int i = 0; i < request.size(); i++)
				{
					if (popId == request[i].getId())
					{
						t4 = request[i].getInTime();
						t5 = time(NULL);
						takeoff_time = takeoff_time + (t5 - t4);
						break;
					}
				}
				this_thread::sleep_for(chrono::seconds(30));
			}
		}
		runway2.setStatus(0);
	}
}


void Airport::operation1(time_t t1)
{
	while (1)
	{
		if (time(NULL) < t1)
		{
			startOperation();
		}
		else
		{
			float average;
			cout << "\nLanding count ";
			landingQueue.displayCount();

			cout << "\nTakeoff count ";
			takeoffQueue.displayCount();

			cout << "\nLanding Queue\n";
			landingQueue.displayQueue();

			cout << "\nTakeoff  Queue\n";
			takeoffQueue.displayQueue();
			cout << "\nAverage time in landing queue ";
			average = (float)landing_time / 60;
			cout << "\nAverage time in takeoff queue ";
			average = (float)takeoff_time / 60;
			break;
		}
	}
}

void Airport::operation2(time_t t2)
{
	
	while (1)
	{
		if (time(NULL) < t2)
		{
			checkRunway1();
		}
		else
		{
			break;
		}

	}
}

void Airport::operation3(time_t t3)
{
	while (1)
	{
		if (time(NULL) < t3)
		{
			checkRunway2();
		}
		else
		{
			break;
		}

	}
}