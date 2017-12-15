#ifndef Products_HEADER													//to delete the file which is already present with the same name of this header file 
#define Products_HEADER													//define a new file with current file name
#pragma once															//source file to be included only once in a single compilation
#include<vector>														//include vector to use vector variables and function
#include<string>														//include string to use string variables and function
#include<iostream>														//defines the standard input/output stream objects
using namespace std;													//to use features of Standard Library
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
	int getChoice();
};

#endif
