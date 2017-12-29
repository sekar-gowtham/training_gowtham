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
	int random_number;
	time_t end_time;
	random_number = rand() % 600;
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
	string aero_id;
	Request r;
	time_t t;
	aero_id = genarateAirId();
	airobj.setAirplaneId(aero_id);
	airways.push_back(airobj);
	rid = airobj.generateRequestId();
	req = airobj.generateRequestType(aero_id);
	r.setAeroId(aero_id);
	r.setRequestId(rid);
	r.setRequestType(req);
	t = time(NULL);
	r.setInTime(t);
	if (req == "landing")
	{
		landingQueue.push(r);
	}
	else
	{
		takeoffQueue.push(r);
	}		
}

void Airport::checkRunway1(time_t total_time)
{
	bool check;
	int start_time;
	time_t end_time;
	Request r;
	if (runway1.getStatus() == 0)
	{
		runway1.setStatus(1);
		check = landingQueue.isEmpty();
		if (1==check)
		{
			r=landingQueue.pop();
			start_time = r.getInTime();
			end_time = time(NULL);
			landing_time = landing_time + (end_time - start_time);
			
			landing.push_back(r);

			if ((end_time - total_time) < time_taken)
			{
				time_taken = (end_time - total_time);
			}
			this_thread::sleep_for(chrono::seconds(time_taken));
		}
		else
		{
			check = takeoffQueue.isEmpty();
			if (1 == check)
			{
				r = takeoffQueue.pop();
				start_time = r.getInTime();
				end_time = time(NULL);
				takeoff_time = takeoff_time + (end_time - start_time);
				takeoff.push_back(r);
				if ((end_time - total_time) < time_taken)
				{
					time_taken = (end_time - total_time);
				}
				this_thread::sleep_for(chrono::seconds(time_taken));
			}
		}
		runway1.setStatus(0);
	}
}

void Airport::checkRunway2(time_t total_time)
{
	bool check;
	int start_time;
	time_t end_time;
	Request r;
	if (runway2.getStatus() == 0)
	{
		runway2.setStatus(1);
		check = landingQueue.isEmpty();
		if (1 == check)
		{
			r = landingQueue.pop();
			start_time = r.getInTime();
			end_time = time(NULL);
			landing_time = landing_time + (end_time - start_time);
			landing.push_back(r);
			if ((end_time - total_time) < time_taken)
			{
				time_taken = (end_time - total_time);
			}
			this_thread::sleep_for(chrono::seconds(time_taken));
		}
		else
		{
			check = takeoffQueue.isEmpty();
			if (1 == check)
			{
				r = takeoffQueue.pop();
				start_time = r.getInTime();
				end_time = time(NULL);
				takeoff_time = takeoff_time + (end_time - start_time);
				takeoff.push_back(r);
				if ((end_time - total_time) < time_taken)
				{
					time_taken = (end_time - total_time);
				}
				this_thread::sleep_for(chrono::seconds(time_taken));
			}
		}
		runway2.setStatus(0);
	}
}

void Airport::operation1(time_t total_time)
{
	while (1)
	{
		if (time(NULL) < total_time)
		{
			startOperation();
		}
		else
		{
		float average;
			cout << "\nLanding count " << landingQueue.getCount();
			cout << "\nTakeoff count " << takeoffQueue.getCount();
			cout << "\nLanding Queue\n";
			landingQueue.displayQueue();
			cout << "\nTakeoff  Queue\n";
			takeoffQueue.displayQueue();
			cout << "\ntotal landing wait time  " << landing_time;
			average = (float)landing_time / (landingQueue.getCount());
			cout << "\nAverage landing time " << average;
			cout << "\ntotal takeoff wait time " << takeoff_time;
			average = (float)takeoff_time / (takeoffQueue.getCount());
			cout << "\nAverage takeoff time " << average;
			break;
		}
	}
}

void Airport::operation2(time_t total_time)
{
	while (1)
	{
		if (time(NULL) < total_time)
		{
			checkRunway1(total_time);
		}
		else
		{
			break;
		}
	}
}

void Airport::operation3(time_t total_time)
{
	while (1)
	{
		if (time(NULL) < total_time)
		{
			checkRunway2(total_time);
		}
		else
		{
			break;
		}
	}
}