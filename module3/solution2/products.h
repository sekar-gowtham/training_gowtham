#ifndef Products_HEADER
#define Products_HEADER
#pragma once

#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Products
{
public:
	float product_price;
	int height;
	bool flag = 0;
	vector <string> product_name;
	Products *left;
	Products *right;
	Products();
	~Products();
	Products* insert(string,float,Products *node);
	void inOrder(Products *temp);
	Products* balance(Products *temp);
	int findBalanceFactor(Products *temp);
	int findHeight(Products *temp);
	int max(int l_height,int r_height);
	void display(Products *temp);
	Products* leftRotate(Products *temp);
	Products* rightRotate(Products *temp);
	Products* mirror(Products *node);
	int numberOfProducts(Products *temp,float price);
	//Products* duplicate(Products *node);
	
};

#endif
