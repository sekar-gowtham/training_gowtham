#include "XmlParsing.h"


XmlParsing::XmlParsing()
{
}


XmlParsing::~XmlParsing()
{
}

void XmlParsing::parse_detail(char buffer[])
{

	xml_document<> document;
	document.parse<0>(&buffer[0]);
	xml_node<> *RootNode = document.first_node();
	xml_node<> *FirstNode = RootNode->first_node();
	string TagName = FirstNode->name();
	if (TagName.compare("gameinfo") == 0)
	{
		//send game info to particular client

	}
	else if (TagName.compare("letter") == 0)
	{
		string XmlLetter = FirstNode->value();
		char Letter[1];
		strcpy(Letter, XmlLetter.c_str());
		int CharIndex;
		bool flag = 0;

		for (CharIndex = 0; CharIndex < strlen(Word); CharIndex++)
		{
			if (Word[CharIndex] == tolower(Letter[0]) || Word[CharIndex] == toupper(Letter[0]))
			{
				Dash[CharIndex] = Word[CharIndex];
				flag = 1;
			}
		}

		if (flag == 0)
		{
			WrongGuess[MaximumGuess - RemainingGuess] = Letter[0];
			RemainingGuess--;
		}
		int Count = calculate_number_of_dash(Dash);
		if (Count == 0)
		{
			Result = "win";
		}
		else if (RemainingGuess == 0)
		{
			Result = "lose";
		}
		else
		{
			Result = "playing";
		}
		//send game info to the all UI which is in same game id
		string GameInfo = "<hangman></gameinfo><gameid> " + to_string(GameId) + "</gameid></gameinfo></hangman>";

	}
}