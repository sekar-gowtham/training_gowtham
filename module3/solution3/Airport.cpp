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

	int random_number;
	time_t end_time;
	
	//srand(time(NULL));


	random_number = rand() % 60;
	end_time = time(NULL) + random_number;
	/*while (1)
	{
		if (time(NULL) > end_time)
		{*/
			aid = "AID" + to_string(id);
			id++;
			

			airobj.setAirplaneId(aid);
			
			airways.push_back(airobj);
			//break;
		/*}
	}*/
	
	return aid;
	
}
void Airport::startOperation()
{
	
	aero_id = genarateAirId();

	req = airobj.generateRequest(aero_id);

	if (req == "landing")
	{
		landingQueue.push(aero_id);
	}
	else
	{
		takeoffQueue.push(aero_id);
	}
				
}

void Airport::checkRunway1()
{

	bool check1 = 0;
	check1 = landingQueue.pop();


	if (1 == check1)
	{
		cout << "\nlanding performed"
	}
	else
	{
		check1 = takeoffQueue.pop();

		if (1 == check1)
		{
			cout << "\ntakeoff performed"
		}
	/*bool check=0;
	

	if (runway1.getStatus() == 0)
	{
		runway1.setStatus(1);
		
		check=landingQueue.pop();
		

		if (1 == check)
		{
			this_thread::sleep_for(chrono::seconds(10));

			
		}
		else
		{
			check = takeoffQueue.pop();
			
			if (1 == check)
			{
				this_thread::sleep_for(chrono::seconds(10));

			}
		}
		runway1.setStatus(0);
		
	}*/
}

void Airport::checkRunway2()
{
	bool check1 = 0;
	check1 = landingQueue.pop();


	if (1 == check1)
	{
		cout << "\nlanding performed"
	}
	else
	{
		check1 = takeoffQueue.pop();

		if (1 == check1)
		{
			cout << "\ntakeoff performed"
		}

	/*bool check1=0;
	
	if (runway2.getStatus() == 0)
	{
		runway2.setStatus(1);
		
		check1 = landingQueue.pop();
		
		
		if (1 == check1)
		{
			this_thread::sleep_for(chrono::seconds(10));
		}
		else
		{
			check1 = takeoffQueue.pop();
			
			if (1 == check1)
			{
				this_thread::sleep_for(chrono::seconds(10));

			}
		}
		runway2.setStatus(0);
		
	}*/
}


void Airport::operation1(time_t t1)
{
	startOperation();
	/*while (1)
	{
		if (time(NULL) < t1)
		{
			startOperation();
		}
		else
		{
			int i;
			
			cout << "\nLanding count ";
			landingQueue.displayCount();
			
			cout << "\nTakeoff count ";
			takeoffQueue.displayCount();
			
			cout << "\nLanding Queue\n";
			landingQueue.displayQueue();
			
			cout << "\nTakeoff  Queue\n";
			takeoffQueue.displayQueue();
			break;
		}
	}*/
}

void Airport::operation2(time_t t2)
{
	checkRunway1();
	/*while (1)
	{
		if (time(NULL) < t2)
		{
			checkRunway1();
		}
		else
		{
			break;
		}

	}*/
}
void Airport::operation3(time_t t3)
{
	checkRunway2();
	/*while (1)
	{
		if (time(NULL) < t3)
		{
			checkRunway2();
		}
		else
		{
			break;
		}

	}*/
}