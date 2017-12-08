#include "empQueue.h"
#include "company.h"
#include "employee.h"
#include<vector>
empQueue::empQueue()
{
	front = -1;
	rear = -1;
}

　
empQueue::~empQueue()
{
}
void empQueue::projectToBench()
{
	
	
	int id = 0;
	int result = 0;
	cout << "\n\nEnter employee id ";
	cin >> id;
	//id = mt.validation();	
	result = binarySearch(id);
	cout << emp.department[0];
	if (-1 == result)
	{
		cout << "\n\nEmployee not found";
		//cout << "result" << result;
	//	cout << emp.department[result];
	}
	else
	{
		bench.push_back(id);
		emp.department[result] = "ABC";
		cout << "\n\nEmployee moved to bench";

	}
}

//int empQueue::binarySearch(int temp_id)
//{
//
//	int size1 = 0;
//	int first = 0;
//	int middle = 0;
//	int last = 0;
//	size1 = emp.emp_id.size();
//	
//
//	while (first <= last)
//	{
//		middle = (first + last) / 2;
//		if (emp.emp_id[middle] == temp_id)
//		{
//			return middle;
//		}
//		if (emp.emp_id[middle] < temp_id)
//		{
//			first = middle + 1;
//		}
//		if (emp.emp_id[middle] > temp_id)
//		{
//			last = middle - 1;
//		}
//	}
//	return -1;
//}

void empQueue::viewBench()
{

}
