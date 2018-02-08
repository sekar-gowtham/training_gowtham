#include "ServerClass.h"


ServerClass::ServerClass()
{

}


ServerClass::~ServerClass()
{
}
int ServerClass::calculate_number_of_dash(char Word[])
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
void ServerClass::receive_message(SOCKET client, int GameId,char* Word)
{
	char buffer[1024];
	char buffer1[1024] = "hi how r u";
	int ReceivedBytes = 0;
	char WrongGuess[MaximumGuess];
	string TagName;
	int RemainingGuess = MaximumGuess;
	string Result;
	char Dash[20];

	int Index = 0;
	for (Index = 0; Index < strlen(Word); Index++)
	{
		if (!isspace(Word[Index]))
		{
			Dash[Index] = '_';
		}
		else
		{
			Dash[Index] = ' ';
		}
	}


	while (ReceivedBytes != -1)
	{
		//change client sockaddr using DB
		
		ReceivedBytes = recv(client, buffer, sizeof(buffer), 0);
		if (ReceivedBytes > 0);
		{

			xml.parse_detail(buffer);

			send(client, buffer1, sizeof(buffer1), 0);
		}
	}
}
void ServerClass::accept_connection()
{
	if (WSAStartup(MAKEWORD(2, 0), &WSAData) != 0)
	{
		cout << "\nWSA startup faild ";
	}
	WSAStartup(MAKEWORD(2, 0), &WSAData);

	if ((server = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		cout << "\nCould not create socket ";
	}
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(138);
	if ((::bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr))) < 0)
	{
		cout << "\nbind error ";
	}
	listen(server, 3);
	cout << "\nListening for incoming connections..." << endl;
	char buffer[1024];
	char buffer1[1024] ="hi how r u";
	int clientAddrSize = sizeof(clientAddr);
	while (1)
	{
		if ((client[ClientCount] = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
		{
			cout << "Client connected!" << endl;
		
			
			//send game details to UI

			recv(client[ClientCount], buffer, sizeof(buffer), 0);

			xml_document<> document;
			document.parse<0>(&buffer[0]);
			xml_node<> *RootNode = document.first_node();
			xml_node<> *FirstNode = RootNode->first_node();
			string TagName = FirstNode->name();
			if (TagName.compare("creategame") == 0)
			{
				//create game id using DB
				//GameId++;
				
				xml_node<> *CategoryNode = FirstNode->first_node("category");
				string Category = CategoryNode->value();
				xml_node<> *LevelNode = FirstNode->first_node("level");
				string Level = LevelNode->value();
				xml_node<> *UserNameNode = RootNode->first_node("username");
				string UserName = UserNameNode->value();
				//send category and difficulty level to DB and get a word
				

				receive[GameId] = thread(&ServerClass::receive_message, this, client[GameId], GameId,Word);
				//send game id , username ,client sockaddr , word to DB
			}
			else if (TagName.compare("joingame") == 0)
			{
				xml_node<> *GameIdNode = FirstNode->first_node("gameid");
				string GameId = GameIdNode->value();
				xml_node<> *UserNameNode = RootNode->first_node("username");
				string UserName = UserNameNode->value();

				//send  game id , username ,client sockaddr to DB
			}
			document.clear();

			memset(buffer, 0, sizeof(buffer));
			ClientCount++;
		}
		else 
		{
			cout << "Client not connected!" << endl;
		}
	}
	cout << "Client disconnected." << endl;
	for (int j = 0; j < ClientCount; j++)
	{
		receive[j].join();
	}
}
