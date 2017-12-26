#include <thread>
#include <iostream>
#include <ctime> 
#include "Airport.h"


using namespace std;

void main()
{
	Airport cbe;

	/*cbe.firstOperation();
	cbe.checkRunway1();
	cbe.checkRunway2();*/
	
	time_t total_time;
	total_time = time(NULL)+200;
	
	

	thread thread1(&Airport::firstOperation, cbe,total_time);


		while (time(NULL) < total_time)
		{
			
			
			/*thread thread2(&Airport::checkRunway1, cbe);
			thread thread3(&Airport::checkRunway2, cbe);*/

			
			
			/*cbe.checkRunway1();
			cbe.checkRunway2();*/
		}

	/*	thread thread2(&Airport::checkRunway1, cbe);

		thread thread3(&Airport::checkRunway2, cbe);*/
	
	
	thread1.join();
	/*thread2.join();
	thread3.join();*/

	
	cbe.display();
	
	cin.get();
}


