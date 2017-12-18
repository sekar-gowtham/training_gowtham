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
	int size;
	float search_price;
	int choice = 0;
	bool error = 0;
	
	while (1)
	{
		cout << "\n\n1.Add a product\n2.display all products\n3.number of products with given price";
		cout<<"\n4.Mirror copy of given tree\n0.Exit\nEnter your choice ";
		choice=pen.getChoice();																						//get the choice from the user
		switch (choice)
		{
		case 1:
			cout << "\nEnter name ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter price ";
			do
			{
				error = 0;
				cin >> price;
				if (cin.fail())																		// this condition will true when the user enters the string
				{
					cout << "\nPlease enter the price " << endl;
					error = 1;
					cin.clear();																	//clearing the error flags of cin
					cin.ignore(numeric_limits<streamsize>::max(), '\n');							//ignore the wrong input
				}
			} while (1 == error);
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
				cout << "\nEnter the price you want to search ";
				do
				{
					cin >> search_price;
					error = 0;
				
					if (cin.fail())																		// this condition will true when the user enters the string
					{
						cout << "\nPlease enter the price " << endl;
						error = 1;
						cin.clear();																	//clearing the error flags of cin
						cin.ignore(numeric_limits<streamsize>::max(), '\n');							//ignore the wrong input
					}
				} while (1 == error);
				

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
