#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <thread>
#include <winsock2.h>

using namespace std;
void receive_message(SOCKET server)
{
	char buffer1[1024];
	while (1)
	{
		recv(server, buffer1, sizeof(buffer1), 0);
		cout << "message received " << buffer1 << endl;
	}
}
int main()
{
	WSADATA WSAData;
	SOCKET server;
	SOCKADDR_IN addr;
	int i;
	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(138);

	connect(server, (SOCKADDR *)&addr, sizeof(addr));
	cout << "Connected to server!" << endl;
	char buffer1[1024];
	char buffer[1024] = "<hangman><username>computer</username></hangman>";



	/*	send(server, buffer, sizeof(buffer), 0);
	cout << "Message sent!" << endl;
	recv(server, buffer1, sizeof(buffer1), 0);
	cout << "message received " << buffer1 << endl;*/


	thread receive(receive_message, server);
	while (1)
	{
		cout << "Enter msg ";
		cin >> buffer;
		send(server, buffer, sizeof(buffer), 0);
		cout << "Message sent!" << endl;
	}






	//closesocket(server);
	WSACleanup();
	cout << "Socket closed." << endl << endl;
	cin.get();
	cin.ignore(1000, '\n');

}