#pragma once
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include <iostream>
#include <thread>
#include <winsock2.h>
#pragma comment(lib,"libws2_32.a")
using namespace std;
using namespace rapidxml;
class ServerClass
{
private:
	int ClientCount = 0;
	SOCKET server, client[7];
	WSADATA WSAData;
	SOCKADDR_IN serverAddr, clientAddr;
	thread receive[4];

public:
	xml_document<> document;
	ServerClass();
	~ServerClass();
	void accept_connection();
	void send_message();
	void receive_message(SOCKET client);
};

