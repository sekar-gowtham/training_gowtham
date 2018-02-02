#include <iostream>
#include <winsock2.h>

using namespace std;

int main()
{
	WSADATA WSAData;

	SOCKET server, client;

	SOCKADDR_IN serverAddr, clientAddr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(139);

	bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
	listen(server, 0);

	cout << "Listening for incoming connections..." << endl;

	char buffer[1024];
	char buffer1[1024] = "hi from server";
	int clientAddrSize = sizeof(clientAddr);
	if ((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
	{
		cout << "Client connected!" << endl;
		recv(client, buffer, sizeof(buffer), 0);
		cout << "Client says: " << buffer << endl;
		memset(buffer, 0, sizeof(buffer));

		send(client, buffer1, sizeof(buffer1), 0);
		cout << "Message sent!" << endl;
		closesocket(client);
		cout << "Client disconnected." << endl;
	}
	cin.get();
	cin.ignore(1000, '\n');
}

