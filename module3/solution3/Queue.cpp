#include "Queue.h"


Queue::Queue()
{
}


Queue::~Queue()
{
}

void Queue::displayQueue()
{
	for (int index = 0; index < reqst.size(); index++)
	{
		cout << "\nAirplane id " << reqst[index].getId();
		cout << "\nRequest id " << reqst[index].getReqId();
	}

}

Request Queue::pop()
{
	Request rst;
	if (reqst.size() != 0)
	{
		this->count++;
		front++;
		rst = reqst[0];
		reqst.erase(reqst.begin());
		return rst;
	}
	
	

}



void Queue::displayCount()
{
	cout << this->count;
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
		return 0;
	}
	else
	{
		return 1;
	}
}