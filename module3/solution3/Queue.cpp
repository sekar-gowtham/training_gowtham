#include "Queue.h"


Queue::Queue()
{
}


Queue::~Queue()
{
}


bool Queue::pop()
{
	if (landing_front != landing_rear)
	{
		landing_count++;
		landing_front++;
		return 1;
	}
	else if (takeoff_front != takeoff_rear)
	{
		takeoff_count++;
		takeoff_front++;
		return 1;
	}
	return 0;
}

void Queue::landingTakeoffCount()
{
	cout << "\n\n\nNumber of landing " << landing_count;
	cout << "\nNumber of takeoff " << takeoff_count;

}

void Queue::displayQueue()
{
	int i;
	cout << "\nIn Landing queue ";
	for (i = landing_front; i < landing_rear; i++)
	{
		cout << landingQueue[i].getId() << endl;
	//	cout << landingQueue[i].getReq() << endl;
	}
	cout << "\n In Takeoff queue ";
	for (i = takeoff_front; i < takeoff_rear; i++)
	{
		cout << takeoffQueue[i].getId() << endl;
	//	cout << takeoffQueue[i].getReq() << endl;
	}
}

void Queue::push(string id, string req)
{
	Request r;
	r.setId(id);
	r.setReq(req);
	if (req == "landing")
	{
		landingQueue.push_back(r);
		landing_rear++;
	}
	else
	{
		takeoffQueue.push_back(r);
		takeoff_rear++;
	}

}