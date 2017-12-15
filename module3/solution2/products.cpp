#include "Products.h"														//include Products.h file to use their variables and function

　
Products::Products()
{
	
}

　
Products::~Products()
{
}

int Products::max(int l_height, int r_height)								
{
	return (l_height > r_height ? l_height : r_height);									//return maximum height either left or right subtree height
}

int Products::findHeight(Products* temp)
{
	int height = 0;
	
	if (temp != NULL)
	{
		int l_height = findHeight(temp->left);											//find the height of leftnode
		int r_height = findHeight(temp->right);											//find the height of rightnode
		int temp_height = max(l_height, r_height);
		height = temp_height + 1;														
	}
	return height;																		//return height of subtree
}

int Products::findBalanceFactor(Products* temp)
{
	int l_height = findHeight(temp->left);												//find height of the left subtree of the node
    int r_height = findHeight(temp->right);												//find height of the right subtree of the node
    int b_factor = r_height - l_height;													//calculate balance factor

	return b_factor;
}

Products* Products::leftRotate(Products *parent)										
{
	Products *temp;
	temp = parent->right;																//assign right child of  parent to temp
	parent->right = temp->left;															//assign left child of temp as right child of parent
	temp->left = parent;																//assign parent as left child of temp
	return temp;
}

Products* Products::rightRotate(Products *parent)
{
	Products *temp;
	temp = parent->left;																//assign left child of  parent to temp
	parent->left = temp->right;															//assign right child of temp as left child of parent
	temp->right = parent;																//assign parent as right child of temp
	return temp;
}

Products* Products::balance(Products *temp)
{
	int b_factor;
	b_factor = findBalanceFactor(temp);
	
	if (b_factor == 2)																	//if balance factor is 2 then right subtree of node is unbalanced
	{
		if (findHeight(temp->right) < 0)
		{
			temp->right = rightRotate(temp->right);
		}
		return leftRotate(temp);
	}
	else if (b_factor==-2)																//if balance factor is -2 then left subtree of node is unbalanced
	{
		if (findHeight(temp->left) > 0)
		{
			temp->left = leftRotate(temp->left);
		}
		return rightRotate(temp);
	}
	return temp;
	
}

Products* Products::insert(string name,float price, Products *node)
{
	if (node == NULL)
	{
		node = new Products;
		node->product_price = price;
		node->product_name.push_back(name);
		node->left = NULL;
		node->right = NULL;
		flag = 1;
		cout << "\nProduct added successfully";
	}
	else if (price < node->product_price)						
	{
		node->left=insert(name, price,node->left);										//if price is less than the price of the node move left side of the tree
		node = balance(node);
	}
	else if (price > node->product_price)
	{
		node->right=insert(name, price, node->right);									//if price is greater than the price of the node move right side of the tree
		node = balance(node);
	}
	else if (price == node->product_price)
	{
		node->product_name.push_back(name);												//if price is equal to the price of the node, add name to the vector of that node
	}
	

	return node;
}

void Products::inOrder(Products *temp)
{
	if (flag==0)
	{
		cout << "\n Tree is empty";
	}
	else if (temp != NULL)
	{

		inOrder(temp->left);															//travel left side of the tree
		display(temp);																	//print the name and price of the product
		inOrder(temp->right);															//travel right side of the tree
	}
}

void Products::display(Products *temp)
{
	int iterate;
	cout << "\n\n\nProducts name:";
	for (iterate = 0; iterate < temp->product_name.size(); iterate++)
	{
		cout << ",    " << temp->product_name[iterate];									//print product name
	}
	cout << "\nProducts Prize     " << temp->product_price;								//print product price
}

　
int Products::numberOfProducts(Products *temp,float price)
{
	int f = 0;
	
	 if (temp != NULL)
	 {
		if (temp->product_price > price)												//if price is less than the price of the node move left side of the tree
		{
			f=numberOfProducts(temp->left, price);
		}
		else if (temp->product_price < price)
		{
			f=numberOfProducts(temp->right, price);										//if price is greater than the price of the node move right side of the tree
		}
		else if (temp->product_price == price)
		{
			return temp->product_name.size();											//if price is equal to the price of the node return size of the product name
		}
		else
		{
			return -1;																	//if the price doesn't match with any node of the tree then return -1 
		}

	}
	return f;
}

Products* Products::mirror(Products *node)												//create mirror copy of the tree
{
	Products *temp = new Products;
	if (node == NULL)
		return NULL;
		
		temp->product_price = node->product_price;										//assign product price to the new tree from original tree
		temp->product_name = node->product_name;										//assign product name to the new tree from original tree
		temp->left = mirror(node->right);												//assign right node of original tree as left node of new tree
		temp->right = mirror(node->left);												//assign left node of original tree as right node of new tree
		
	
	return temp;
}

int Products::getChoice()
{
	
	int choice;
	int error = 0;
	do
	{
		error = 0;

		cin >> choice;
		
		if (cin.fail())																			//this condition will true when the user enters the string
		{
			cout << "\nEnter the valid choice" << endl;
			error = 1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	
	} while (1 == error);
	return choice;
}
