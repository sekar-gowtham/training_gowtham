#include "Queue.h"

　
Queue::Queue()
{
}

　
Queue::~Queue()
{
}
void Queue::push(string id,string req)
{
	Request r;
	if (req == "landing")
	{
		landingQueue.push_back(q);
	}
	else
	{
		takeoffQueue.push_back(q);
	}

}
