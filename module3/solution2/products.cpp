#include "Products.h"

　
Products::Products()
{
	
}

　
Products::~Products()
{
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
	}
	else if (price < node->product_price)
	{
		node->left=insert(name, price,node->left);
	}
	else if (price > node->product_price)
	{
		node->right=insert(name, price, node->right);
	}
	else if (price == node->product_price)
	{
		node->product_name.push_back(name);
	}

	return node;
}

void Products::inOrder(Products *temp)
{
	if (temp != NULL)
	{
		
		inOrder(temp->left);
		cout << temp->product_price << "\t";
		inOrder(temp->right);
	}

}
