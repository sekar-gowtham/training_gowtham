#include <iostream>
#include"BusinessLogic.h"
using namespace std;

void main()
{
	BusinessLogic Logic;
	int Index;
	char Character;
	int Chance = Logic.get_remaining_guess();
	char *Word;
	int NumberOfDash = Logic.get_number_of_dash();

	Word = Logic.display_dash();
	for (Index = 0; Index < strlen(Word); Index++)
	{
		cout << Word[Index] << " ";
	}
	while (Chance && NumberOfDash)
	{
		cout << "\n\nEnter a Character ";
		cin >> Character;
		Word = Logic.character_input(Character);
		for (Index = 0; Index < strlen(Word); Index++)
		{
			cout << Word[Index] << " ";
		}
		Chance = Logic.get_remaining_guess();
		NumberOfDash = Logic.get_number_of_dash();
		cout << "\n\nWrong guesses: ";
		cout << Logic.get_wrong_guess() << endl;
	}
	if (NumberOfDash == 0)
	{
		cout << "\nYou win";
	}
	else if (Chance == 0)
	{
		cout << "\nYou lose";
	}
	cin.get();
	cin.ignore(1000, '\n');
}
