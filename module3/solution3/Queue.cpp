#include "Queue.h"


Queue::Queue()
{
}


Queue::~Queue()
{
}

int Queue::displayQueue()
{
	if (reqst.size() == 0)
	{
		cout << "\nEmpty";
		return 0;
	}
	else
	{
		int waiting_time=0;
		for (int index = 0; index < reqst.size(); index++)
		{
			cout << "\nAirplane id " << reqst[index].getId();
			cout << "\nRequest id " << reqst[index].getReqId()<<endl;
			waiting_time = waiting_time + reqst[index].getIntime();
		}
		return waiting_time;
	}
}

Request Queue::pop()
{
	Request rst;
	
		this->count++;
		front++;
		rst = reqst[0];
		reqst.erase(reqst.begin());
		return rst;
}

int Queue::getCount()
{
	return this->count;
}

void Queue::push( Request r)
{
	reqst.push_back(r);
		rear++;
}

bool Queue::isEmpty()
{
	if (reqst.size() == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
