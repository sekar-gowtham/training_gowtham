#include "Queue.h"
#include <ctime>

Queue::Queue()
{
}


Queue::~Queue()
{
}

int Queue::displayQueue()																	//display the unprocessed request
{
	if (request.size() == 0)																//print empty if the request queue is empty
	{
		cout << "Empty\n";
		return 0;
	}
	else
	{
		int waiting_time = 0;
		for (int index = 0; index < request.size(); index++)								//if the queue is not empty print the request queue
		{
			cout << "\nAirplane id " << request[index].getId();
			cout << "\nRequest id " << request[index].getReqId() << endl;
			waiting_time = waiting_time +(time(NULL)- request[index].getInTime());
		}
		return waiting_time;
	}
}

Request Queue::pop()																		//pop the request which comes first among the queue
{
	Request pop_request;
	this->count++;
	pop_request = request[0];
	request.erase(request.begin());
	return pop_request;
}

int Queue::getCount()																		//get the number of landing and takeoff performed
{
	return this->count;
}

void Queue::push(Request newRequest)														//push the request into the queue
{
	request.push_back(newRequest);
}

bool Queue::isEmpty()																		//check whether the queue is empty or not
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

int Queue::calculateQueueSize()																//calculate count of unprocessed request
{
	return request.size();
}
