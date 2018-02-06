#include <thread>
#include <iostream>
#include <string>
#include <winsock2.h>
#include <sstream>
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "ServerClass.h"
using namespace std;
using namespace rapidxml;
void foo()
{

}
int main()
{
	ServerClass Server;
	//Server.accept_connection();
	thread AcceptConnection(&ServerClass::accept_connection, &Server);

	thread c(foo);

	//thread ReceiveMessage(&ServerClass::receive_message, &Server);
	//xml_document<> document;
	//WSADATA WSAData;

	//SOCKET server, client;

	//SOCKADDR_IN serverAddr, clientAddr;

	//WSAStartup(MAKEWORD(2, 0), &WSAData);
	//server = socket(AF_INET, SOCK_STREAM, 0);

	//serverAddr.sin_addr.s_addr = INADDR_ANY;
	//serverAddr.sin_family = AF_INET;
	//serverAddr.sin_port = htons(138);

	//bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
	//listen(server, 0);

	//cout << "Listening for incoming connections..." << endl;

	//char buffer[1024];
	//char buffer1[1024] = "hi from server";
	//
	//int clientAddrSize = sizeof(clientAddr);
	//
	//	if ((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
	//	{
	//		cout << "Client connected!" << endl;
	//		recv(client, buffer, sizeof(buffer), 0);
	//		cout << "Client says: " << buffer << endl;

	//		document.parse<0>(&buffer[0]);
	//		
	//		xml_node<> *node = document.first_node();
	//		xml_node<> *node1 = node->first_node();
	//		//cout << document;
	//		cout << "username = " << node1->value() << endl;
	//		memset(buffer, 0, sizeof(buffer));
	//		while (1)
	//		{
	//			cout << "\nEnter msg ";
	//			cin >> buffer1;
	//			send(client, buffer1, sizeof(buffer1), 0);
	//			cout << "Message sent!" << endl;
	//		}
	//		closesocket(client);
	//		cout << "Client disconnected." << endl;
	//	}
	AcceptConnection.join();
	
	cin.get();
	cin.ignore(1000, '\n');
}
