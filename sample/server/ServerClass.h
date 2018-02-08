#pragma once
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include <iostream>
#include <thread>
#include<string>
#include "XmlParsing.h"
#include <winsock2.h>
#pragma comment(lib,"libws2_32.a")
#define MaximumGuess 6
using namespace std;
using namespace rapidxml;
class ServerClass
{
private:
	char* Word;
	int ClientCount = 0;
	
	int GameId = 0;
	SOCKET server, client[7];
	WSADATA WSAData;
	SOCKADDR_IN serverAddr, clientAddr;
	thread receive[4];
	
	XmlParsing xml;
public:
	xml_document<> document;
	ServerClass();
	~ServerClass();
	void accept_connection();
	void send_message();
	void receive_message(SOCKET client,int GameId,char* Word);
	void game_detail(SOCKET client);
	void create_game(SOCKET client);
	int calculate_number_of_dash(char[]);

};

