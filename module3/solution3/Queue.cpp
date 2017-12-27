#include "Queue.h"


Queue::Queue()
{
}


Queue::~Queue()
{
}

void Queue::setFront(int i)
{
	this->front = i;
}

int Queue::getFront()
{
	return this->front;
}

void Queue::displayQueue()
{
	int i;

	if (id.size()==0)
	{
		cout << "empty" << endl;
	}
	else
	{
		for (i = 0; i < id.size(); i++)
		{
			cout << id[i] << endl;
			
		}
		cout << "frnt " << this->front;
	}

}

bool Queue::pop()
{
	
	if (id.size() != 0)
	{
		this->count++;
		front++;
		id.erase(id.begin());
		return true;
	}
	else
	{
		return false;
	}
}

void Queue::displayCount()
{
	cout << this->count;
}



void Queue::push(string aid)
{
	
		id.push_back(aid);
		
		rear++;

}