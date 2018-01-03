#include "Airport.h"

Airport::Airport()
{

}

Airport::~Airport()
{
}

string Airport::genarateAirId()													//generate airplane id
{
	string aid;
	int random_number;
	time_t end_time;
	random_number = rand() % time_interval;
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

void Airport::generateRequest()													//generate airplane request
{
	Airplane airobj;
	string req;
	string rid;
	string aero_id;
	Request newRequest;
	time_t t;
	aero_id = genarateAirId();
	rid = airobj.generateRequestId();
	req = airobj.generateRequestType(aero_id);
	newRequest.setAeroId(aero_id);
	newRequest.setRequestId(rid);
	newRequest.setRequestType(req);
	t = time(NULL);
	newRequest.setInTime(t);
	if (req == "landing")
	{
		landingQueue.push(newRequest);											//push into landing queue if the request is landing
	}
	else
	{
		takeoffQueue.push(newRequest);											//push into takeoff queue if the request is takeoff
	}
}

void Airport::checkRunway1(time_t total_time)
{
	int start_time;
	time_t end_time;
	struct tm info;
	Request popedRequest;
	if (runway1.getStatus() == 0)												//check whether the runway1 is free or not
	{
		if (!landingQueue.isEmpty())											//check whether the queue is empty or not
		{
			runway1.setStatus(1);
			popedRequest = landingQueue.pop();
			start_time = popedRequest.getInTime();
			end_time = time(NULL);
			landing_waiting_time = landing_waiting_time + (end_time - start_time);		
			localtime_s(&info, &end_time);
			cout << "\nRequest id " << popedRequest.getReqId() << " started  landing on runway 1 at " << info.tm_hour << " : " << info.tm_min << " : " << info.tm_sec << endl;
			landed.push_back(popedRequest);

			if ((total_time - end_time) < time_taken)
			{
				time_taken = (total_time - end_time);
			}
			this_thread::sleep_for(chrono::seconds(time_taken));
			end_time = time(NULL);
			localtime_s(&info, &end_time);
			cout << "\nRequest id " << popedRequest.getReqId() << " finished landing on runway 1 at " << info.tm_hour << " : " << info.tm_min << " : " << info.tm_sec << endl;
			runway1.setStatus(0);
		}
		else
		{
			end_time = time(NULL);
			if ((total_time - end_time) > time_taken)						
			{
				if (!takeoffQueue.isEmpty())									//check whether the queue is empty or not
				{
					runway1.setStatus(1);
					popedRequest = takeoffQueue.pop();
					start_time = popedRequest.getInTime();
					localtime_s(&info, &end_time);								//calculate local time
					takeoff_waiting_time = takeoff_waiting_time + (end_time - start_time);
					cout << "\nRequest id " << popedRequest.getReqId() << " started  takeoff on runway 1 at " << info.tm_hour << " : " << info.tm_min << " : " << info.tm_sec << endl;
					tookoff.push_back(popedRequest);
					this_thread::sleep_for(chrono::seconds(time_taken));
					end_time = time(NULL);
					localtime_s(&info, &end_time);
					cout << "\nRequest id " << popedRequest.getReqId() << " finished takeoff on runway 1 at " << info.tm_hour << " : " << info.tm_min << " : " << info.tm_sec << endl;
					runway1.setStatus(0);
				}
			}
		}
	}
}
void Airport::checkRunway2(time_t total_time)
{
	int start_time;
	time_t end_time;
	Request popedRequest;
	struct tm info;
	if (runway2.getStatus() == 0)												//check whether the runway2 is free or not
	{
		if (!landingQueue.isEmpty())											//check whether the queue is empty or not
		{
			runway2.setStatus(1);
			popedRequest = landingQueue.pop();
			start_time = popedRequest.getInTime();
			end_time = time(NULL);
			landing_waiting_time = landing_waiting_time + (end_time - start_time);
			localtime_s(&info, &end_time);
			cout << "\nRequest id " << popedRequest.getReqId() << " started  landing on runway 2 at " << info.tm_hour << " : " << info.tm_min << " : " << info.tm_sec << endl;
			landed.push_back(popedRequest);
			if ((total_time - end_time) < time_taken)
			{
				time_taken = (total_time - end_time);
			}
			this_thread::sleep_for(chrono::seconds(time_taken));
			end_time = time(NULL);
			localtime_s(&info, &end_time);
			cout << "\nRequest id " << popedRequest.getReqId() << " finished landing on runway 2 at " << info.tm_hour << " : " << info.tm_min << " : " << info.tm_sec << endl;
			runway2.setStatus(0);
		}
		else
		{
			end_time = time(NULL);
			if ((total_time - end_time) > time_taken)
			{
				if (!takeoffQueue.isEmpty())									//check whether the queue is empty or not
				{
					runway2.setStatus(1);
					popedRequest = takeoffQueue.pop();
					start_time = popedRequest.getInTime();
					end_time = time(NULL);
					localtime_s(&info, &end_time);								//calculate local time
					takeoff_waiting_time = takeoff_waiting_time + (end_time - start_time);
					cout << "\nRequest id " << popedRequest.getReqId() << " started  takeoff on runway 2 at " << info.tm_hour << " : " << info.tm_min << " : " << info.tm_sec << endl;
					tookoff.push_back(popedRequest);
					this_thread::sleep_for(chrono::seconds(time_taken));
					end_time = time(NULL);
					localtime_s(&info, &end_time);
					cout << "\nRequest id " << popedRequest.getReqId() << " finished takeoff on runway 2 at " << info.tm_hour << " : " << info.tm_min << " : " << info.tm_sec << endl;
					runway2.setStatus(0);
				}
			}
		}
	}
}

void Airport::callGenerateRequest(time_t total_time)
{
	while (1)
	{
		if (time(NULL) < total_time)
		{
			generateRequest();
		}
		else
		{
			float average;
			int waiting_time;
			cout << "\nLanding count " << landingQueue.getCount();				//display number of landing count
			cout << "\nTakeoff count " << takeoffQueue.getCount();				//display number of takeoff count
			cout << "\n\nLanding Queue\n";
			waiting_time = landingQueue.displayQueue();							//display unprocessed request in landing queue
			landing_waiting_time += waiting_time;
			average = (float)landing_waiting_time / (landingQueue.getCount() + landingQueue.calculateQueueSize());
			cout << "\nAverage landing time " << average / 60 << " minutes ";			//convert seconds into minutes
			cout << "\n\nTakeoff  Queue\n";
			waiting_time = takeoffQueue.displayQueue();							//display unprocessed request in takeoff queue
			takeoff_waiting_time += waiting_time;
			average = (float)takeoff_waiting_time / (takeoffQueue.getCount() + takeoffQueue.calculateQueueSize());
			cout << "\nAverage takeoff time " << average/60 <<" minutes ";				//convert seconds into minutes
			break;
		}
	}
}

void Airport::callCheckRunway1(time_t total_time)
{
	while (1)
	{
		if (time(NULL) < total_time)
		{
			checkRunway1(total_time);												//continuosly call checkRunway to check the runway 1 is free or not
		}
		else
		{
			break;
		}
	}
}

void Airport::callCheckRunway2(time_t total_time)
{
	while (1)
	{
		if (time(NULL) < total_time)
		{
			checkRunway2(total_time);												// continuosly call checkRunway to check the runway 2 is free or not
		}
		else
		{
			break;
		}
	}
}
