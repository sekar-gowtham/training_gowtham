#include "Products.h"

　
Products::Products()
{
	
}

　
Products::~Products()
{
}

int Products::max(int l_height, int r_height)
{
	return (l_height > r_height ? l_height : r_height);
}

int Products::findHeight(Products* temp)
{
	int height = 0;
	
	if (temp != NULL)
	{
		int l_height = findHeight(temp->left);
		int r_height = findHeight(temp->right);
		int temp_height = max(l_height, r_height);
		height = temp_height + 1;
	}
	return height;
}

int Products::findBalanceFactor(Products* temp)
{
	int l_height = findHeight(temp->left);
    int r_height = findHeight(temp->right);
    int b_factor = r_height - l_height;

	return b_factor;
}

Products* Products::leftRotate(Products *parent)
{
	Products *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

Products* Products::rightRotate(Products *parent)
{
	Products *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

Products* Products::balance(Products *temp)
{
	int b_factor;
	b_factor = findBalanceFactor(temp);
	
	if (b_factor == 2)
	{
		if (findHeight(temp->right) < 0)
		{
			temp->right = rightRotate(temp->right);
		}
		return leftRotate(temp);
	}
	else if (b_factor==-2)
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
		node->left=insert(name, price,node->left);
		node = balance(node);
	}
	else if (price > node->product_price)
	{
		node->right=insert(name, price, node->right);
		node = balance(node);
	}
	else if (price == node->product_price)
	{
		node->product_name.push_back(name);
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

		inOrder(temp->left);
		//cout << temp->product_price << "\n";
		display(temp);
		inOrder(temp->right);
	}
}

void Products::display(Products *temp)
{
	int iterate;
	cout << "\n\n\nProducts name:";
	for (iterate = 0; iterate < temp->product_name.size(); iterate++)
	{
		cout << ",    " << temp->product_name[iterate];
	}
	cout << "\nProducts Prize     " << temp->product_price;
}

　
int Products::numberOfProducts(Products *temp,float price)
{
	int f = 0;
	if (temp != NULL)
	{
		if (temp->product_price > price)
		{
			f=numberOfProducts(temp->left, price);
		}
		else if (temp->product_price < price)
		{
			f=numberOfProducts(temp->right, price);
		}
		else if (temp->product_price == price)
		{
			return temp->product_name.size();
		}
		else
		{
			return -1;
		}

	}
	return f;
}

//Products* Products::duplicate(Products *node)
//{
//	Products *temp = new Products;
//	if (node == NULL)
//	{
//		return node;
//	}
//	temp->product_price = node->product_price;
//	temp->left = duplicate(node->left);
//	temp->right = duplicate(node->right);
//	return temp;
//}

Products* Products::mirror(Products *node)
{
	Products *temp = new Products;
	if (node == NULL)
		return NULL;
		
		temp->product_price = node->product_price;
		temp->product_name = node->product_name;
		temp->left = mirror(node->right);
		temp->right = mirror(node->left);
		
	
	return temp;
}

　
