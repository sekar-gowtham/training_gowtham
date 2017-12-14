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
	vector <string> product_name;
	Products *left;
	Products *right;
	Products();
	~Products();
	Products* insert(string,float,Products *node);
	void inOrder(Products *temp);

};

#endif
