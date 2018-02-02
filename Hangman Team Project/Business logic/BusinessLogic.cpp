#include "BusinessLogic.h"
#include <iostream>
using namespace std;

BusinessLogic::BusinessLogic()
{
	
}


BusinessLogic::~BusinessLogic()
{

}
char* BusinessLogic::display_dash()
{
	int Index = 0;
	for (Index = 0; Index < strlen(Word); Index++)
	{
		Dash[Index] = '_';
	}
	return Dash;
}
int BusinessLogic::get_remaining_guess()
{
	return RemainingGuess;
}
int BusinessLogic::get_number_of_dash()
{
	return NumberOfDash;
}
char* BusinessLogic::get_wrong_guess()
{
	return WrongGuess;
}
int BusinessLogic::calculate_number_of_dash(char Word[])
{
	int Index;
	int Count = 0;
	for (Index = 0; Index < strlen(Word); Index++)
	{
		if (Word[Index] == '_')
		{
			Count++;
		}
	}
	return Count;
}
char* BusinessLogic::character_input(char Letter)
{
	int CharIndex ;
	bool flag = 0;

	for (CharIndex = 0; CharIndex < strlen(Word); CharIndex++)
		{
			if (Word[CharIndex] == Letter)
			{
				Dash[CharIndex] = Letter;
				NumberOfDash = calculate_number_of_dash(Dash);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			WrongGuess[MaximumGuess - RemainingGuess] = Letter;
			RemainingGuess--;
		}
		return Dash;
}