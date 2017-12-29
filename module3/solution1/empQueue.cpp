#include "empQueue.h"




empQueue::empQueue()
{
	
}


empQueue::~empQueue()
{
}



void empQueue::push(string id)																    //remove employee from project to bench			
{
	
	int f = 0;
	int iterate = 0;
	employees q;
			for (iterate = front; iterate <bench.size(); iterate++)								//search bench whether the employee is already in bench or not
			{
				if (bench[iterate].getId() == id)
				{
					cout << "Employee already in bench";
					f = 1;
					break;
				}
			}
			if (f == 0)
			{
				q.setId(id);																//push the employee to the bench
				bench.push_back(q);
				cout << "\n\nEmployee moved to bench";
				rear++;
			}
}

string empQueue::pop()
{

	string id;
	if (front == rear)																	//check whether the bench is empty or not
	{
		cout << "\nbench is empty";
		return "abc";
	}
	else
	{
		id = bench[front].getId();
		
		
		front++;

		return id;
	}
}
void empQueue::viewBench()
{
	int iterate;
	
	if (front == rear)																	//check whether the bench is empty or not
	{
		cout << "\nbench is empty";
	}
	else
	{
		cout << "\nEmployees in bench\n\n";
	
		
		for (iterate =front; iterate != bench.size(); ++iterate)
		{
			cout << bench[iterate].getId() << endl;
		}
	
	}
}



