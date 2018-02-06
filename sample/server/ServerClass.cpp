#include "ServerClass.h"


ServerClass::ServerClass()
{
	
}


ServerClass::~ServerClass()
{
}
void ServerClass::receive_message()
{
	//int Iteration = 3;
	char UserName[1024];
	while (1)
	{
		recv(client[0], UserName, sizeof(UserName), 0);
	}
	cout << UserName;
	//receive_message();

}
void ServerClass::accept_connection()
{
	WSADATA WSAData;

	int Iteration = 0;

	SOCKADDR_IN serverAddr, clientAddr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(138);

	bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
	listen(server, 3);

	cout << "Listening for incoming connections..." << endl;
	char buffer1[1024] = "hi from server";
	char UserName[1024];
	int clientAddrSize = sizeof(clientAddr);
	while (1)
	{
	
		if ((client[Iteration] = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
		{
			//receive_message();
			cout << "\nClient connected!" << endl;
			//for (int i = 0; i < Iteration; i++)
			//{
			send(client[Iteration], buffer1, sizeof(buffer1), 0);
				
			//}
		//thread call(&receive_message);
				Iteration++;
			
		}
		else
		{
			cout << "Client Not connected!" << endl;
		}
	}
	//store the UserName in DB
	

}


void ServerClass::send_message()
{
	
}

