#include "Employee.h"

int main()
{
	int size, i;
	Employee a=new Employee(4);
	Employee a1 = Employee(a);
	 
	cout << "Enter no of employee";
	cin >> size;
	for (i = 0; i < size; i++)
	{
		a[i].getdata();
	}
	for (i = 0; i < size; i++)
	{
		a[i].display();
	}
	return 0;
}
	/*Employee* a = new Employee[size];
	cout << "Enter no of employee";
	cin >> size;
	for (i = 0; i < size; i++)
	{
		a[i] = new Employee();
		a[i]->getdata();
	}
	Employee ee[5];
	for (i = 0; i < 5; i++)
	{
		ee[i].getdata();
		ee[i].display();
	}*/
	//return 0;
	//int* a = NULL;   // Pointer to int, initialize to nothing.
	//int n;           // Size needed for array
	//cin >> n;        // Read in the size
	//a = new int[n];  // Allocate n ints and save ptr in a.
	//for (int i = 0; i<n; i++) {
		//a[i] = 0;    // Initialize all elements to zero.
