/*
File name : main.cpp
Purpose : To store product name and it's price
Author : Gowtham

*/

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
	int choice = 0;
	while (1)
	{
		cout << "\n\n1.Add a product\n2.display all products\n3.number of products with given price";
		cout<<"\n4.Mirror copy of given tree\n0.Exit\nEnter your choice ";
		choice=pen.validChoice();																						//get the choice from the user
		switch (choice)
		{
		case 1:
			cout << "\nEnter name ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter price ";
			price = pen.validPrice();
			root=pen.insert(name,price,root);																//pass the data to store in tree
			break;
		case 2:
			pen.inOrder(root);																				//display the tree 
			break;
		case 3:
			pen.numberOfProducts(root);
			break;
		case 4:
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