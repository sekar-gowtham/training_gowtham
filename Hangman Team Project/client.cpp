#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <winsock2.h>
 
using namespace std;
 
int main()
{
    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN addr;
	int i;
	bool g=1;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);
 
    addr.sin_addr.s_addr = inet_addr("172.29.124.236"); 
    addr.sin_family = AF_INET;
    addr.sin_port = htons(139);
 
    connect(server, (SOCKADDR *)&addr, sizeof(addr));
    cout << "Connected to server!" << endl;
	char buffer1[1024];
	char buffer[1024] = { 'h', 'e', 'l', 'l', 'o',' ', 'h', 'e', 'l', 'l', 'o', '.' };
	

	
		send(server, buffer, sizeof(buffer), 0);
		cout << "Message sent!" << endl;

		recvfrom(server, buffer1, sizeof(buffer1), 0, (SOCKADDR *)&addr, &i);
		cout << "message received " << buffer1 << endl;
	
	
		

	closesocket(server);
    WSACleanup();
    cout << "Socket closed." << endl << endl;
	cin.get();
	cin.ignore(1000, '\n');

}

