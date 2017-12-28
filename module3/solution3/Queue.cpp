#include "Queue.h"


Queue::Queue()
{
}


Queue::~Queue()
{
}

void Queue::displayQueue()
{
	int i;
	if (airplane_id.size()==0)
	{
		cout << "empty" << endl;
	}
	else
	{
		for (i = 0; i < airplane_id.size(); i++)
		{
			cout <<"Airplane id  "<< airplane_id[i] <<"  Request id  "<<req_id[i]<<endl;
		}
	}

}

bool Queue::pop()
{
	if (airplane_id.size() != 0)
	{
		this->count++;
		front++;
		airplane_id.erase(airplane_id.begin());
		req_id.erase(req_id.begin());
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

void Queue::push(string aid,string rid)
{
		airplane_id.push_back(aid);
		req_id.push_back(rid);
		rear++;
}

string Queue::getPopId()
{
	string i;
	i = this->req_id[0];
	return i;
}