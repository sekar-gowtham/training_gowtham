#include<iostream>																			//defines the standard input/output stream objects
#include"Products.h"																		//include Products.h file to use their variables and function
using namespace std;																		//to use features of Standard Library 
void main()
{
	string name;
	float price;
	Products pen;
	Products *root=NULL;
	Products *copy = new Products;
	int size;
	float search_price;
	int choice = 0;
	
	while (1)
	{
		cout << "\n\n1.Add a product\n2.display all products\n3.number of products with given price";
		cout<<"\n4.Mirror copy of given tree\n0.Exit\nEnter your choice ";
		choice=pen.getChoice();																						//get the choice from the user
		switch (choice)
		{
		case 1:
			cout << "\nEnter name ";
			cin >> name;
			cout << "Enter price ";
			cin >> price;
			root=pen.insert(name,price,root);																//pass the data to store in tree
			break;
		case 2:
			pen.inOrder(root);																				//display the tree 
			break;
		case 3:
			if (pen.flag == 0)
			{
				cout << "\nTree is empty";
			}
			else
			{
				cout << "\nEnter the price ";
				cin >> search_price;
				size = pen.numberOfProducts(root, search_price);											//to find number of products with same prize
				if (size > 0)
				{
					cout << "\nNumber of products found  " << size;
				}
				else 
				{
					cout << "\nNo product price match with given price ";
				}
			}
			break;
		case 4:
			//copy = pen.duplicate(root);
			copy=pen.mirror(root);																			//create mirror copy of the tree
			pen.inOrder(copy);																				//display the mirror tree
			break;
		case 0:
			exit(0);
		default:
			cout << "\nEnter valid choice ";

		}
	}
}
