
#include<iostream>
#include"Products.h"
using namespace std;
void main()
{
	string name;
	float price;
	Products pen;
	Products *root=NULL;
	int choice = 0;
	
	while (1)
	{
		cout << "\n\n\n1.Add a product\n2.display all products\nEnter your choice ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nEnter name ";
			cin >> name;
			cout << "Enter price ";
			cin >> price;
			root=pen.insert(name,price,root);
			break;
		case 2:
			pen.inOrder(root);
			break;
		default:
			cout << "\nEnter valid choice ";
		case 0:
			exit(0);

		}
	}
}
