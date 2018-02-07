#pragma once
#include <iostream>
#include <thread>
#include <winsock2.h>
#pragma comment(lib,"libws2_32.a")
using namespace std;

class ServerClass
{
private:
	int ClientCount = 0;
	int GameId = 0;
	SOCKET server, client[7];
	WSADATA WSAData;
	SOCKADDR_IN serverAddr, clientAddr;
	thread receive[4];

public:
	
	ServerClass();
	~ServerClass();
	void accept_connection();
	void receive_message(SOCKET client,int GameId);
};