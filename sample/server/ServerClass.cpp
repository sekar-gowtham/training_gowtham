#include "ServerClass.h"


ServerClass::ServerClass()
{
	
}


ServerClass::~ServerClass()
{
}
void ServerClass::create_game(SOCKET client)
{
	//
}
void ServerClass::game_detail(SOCKET client)
{
	// get data from DB and send to UI

}
void ServerClass::receive_message(SOCKET client)
{
	char buffer[1024];
	char buffer1[1024] = "hi how r u";
	int ReceivedBytes = 0;
	string TagName;
	while (ReceivedBytes != -1)
	{
		ReceivedBytes = recv(client, buffer, sizeof(buffer), 0);
		if (ReceivedBytes > 0);
		{
			cout << "\nmessage received " << buffer;
			document.parse<0>(&buffer[0]);
			xml_node<> *node = document.first_node();
			xml_node<> *node1 = node->first_node(); 
			TagName = node1->name();
			if (TagName == "requestgamedetails")
			{
				cout << "\nuser requested game detail";
				game_detail(client);
			}
			else if (TagName == "creategame")
			{
				cout << "\nuser send create game ";
				create_game(client);
			}
			else if (TagName == "joingame")
			{
				cout << "\nuser send join game ";
			}




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
	char buffer1[1024] = { "hi how r u" };
	int clientAddrSize = sizeof(clientAddr);
	while (1)
	{
		if ((client[ClientCount] = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
		{
			cout << "Client connected!" << endl;
			receive[ClientCount] = thread(&ServerClass::receive_message,this, client[ClientCount]);
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

//void ServerClass::send_message()
//{
//	
//}
//
