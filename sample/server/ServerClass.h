#pragma once
#include <iostream>
#include <thread>
#include <winsock2.h>
using namespace std;
class ServerClass
{
private:
	SOCKET server, client[7];
public:
	ServerClass();
	~ServerClass();
	void accept_connection();
	void send_message();
	void receive_message();
};

