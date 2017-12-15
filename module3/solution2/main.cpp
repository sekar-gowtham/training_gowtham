
#include<iostream>
#include"Products.h"
using namespace std;
void main()
{
	string name;
	float price;
	Products pen;
	Products *root=NULL;
	Products *copy = new Products;
	int size;
	float p;
	int choice = 0;
	
	while (1)
	{
		cout << "\n\n1.Add a product\n2.display all products\n3.number of products with given price\n4.Mirror copy of given tree\n0.Exit\nEnter your choice ";
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
		case 3:
			cout << "\nEnter the price ";
			cin >> p;
			size=pen.numberOfProducts(root,p);
			if (size > 0)
			{
				cout << "\nNumber of products found  " << size;
			}
			else
			{
				cout << "\nNo product price match with given price ";
			}
			break;
		case 4:
			//copy = pen.duplicate(root);
			copy=pen.mirror(root);
			pen.inOrder(copy);
			break;
		case 0:
			exit(0);
		default:
			cout << "\nEnter valid choice ";

		}
	}
}
