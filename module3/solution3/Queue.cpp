#include "Queue.h"


Queue::Queue()
{
}


Queue::~Queue()
{
}

int Queue::displayQueue()
{
	if (request.size() == 0)
	{
		cout << "\nEmpty";
		return 0;
	}
	else
	{
		int waiting_time=0;
		for (int index = 0; index < request.size(); index++)
		{
			cout << "\nAirplane id " << request[index].getId();
			cout << "\nRequest id " << request[index].getReqId()<<endl;
			waiting_time = waiting_time + request[index].getIntime();
		}
		return waiting_time;
	}
}

Request Queue::pop()
{
	Request pop_request;
	
		this->count++;
		front++;
		pop_request = request[0];
		request.erase(request.begin());
		return pop_request;
}

int Queue::getCount()
{
	return this->count;
}

void Queue::push( Request r)
{
	request.push_back(r);
		rear++;
}

bool Queue::isEmpty()
{
	if (request.size() == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Queue::calculateQueueSize()
{
	return request.size();
}
