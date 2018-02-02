#pragma once
#include <iostream>
#include <string>
#include "BusinessLogicInterface.h"
#define MaximumGuess 6
class BusinessLogic : public BusinessLogicInterface
{
private:
	char* Word = "asdfgh";
	int RemainingGuess = MaximumGuess;
	char Dash[20];
	int NumberOfDash = strlen(Word);
	char WrongGuess[MaximumGuess];
	
public:
	BusinessLogic();
	~BusinessLogic();
	char* display_dash();
	//void get_username(char*);
	char* character_input(char);
	int get_remaining_guess();
	char* get_wrong_guess();
	int get_number_of_dash();
	int calculate_number_of_dash(char[]);
};

 