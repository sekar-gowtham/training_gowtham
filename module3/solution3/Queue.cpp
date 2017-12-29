#include "Queue.h"


Queue::Queue()
{
}


Queue::~Queue()
{
}

void Queue::displayQueue()
{
	if (reqst.size() == 0)
	{
		cout << "\nEmpty";
	}
	else
	{
		for (int index = 0; index < reqst.size(); index++)
		{
			cout << "\nAirplane id " << reqst[index].getId();
			cout << "\nRequest id " << reqst[index].getReqId()<<endl;
		}
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
		return 0;
	}
	else
	{
		return 1;
	}
}