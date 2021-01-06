#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include "serverTCP.h"
#include "ClientTCP.h"

#pragma comment (lib, "ws2_32.lib")

using namespace std;

void Listener_MessageReceived_Server(serverTCP* listener, int client, string msg);

void Listener_MessageReceived_Client(ClientTCP* sender, int server, string msg);
ssss;
void main()
{
	cout << "1. Server" << endl;
	cout << "2. Client" << endl;
	int n = 0;
	cin >> n;
	if (n == 1) {
		cout << "server is starting!" << endl;
		serverTCP server("127.0.0.1", 54000, Listener_MessageReceived_Server);

		if (server.Init())
		{
			server.Run();
		}
	}
	if (n == 2) {
		cout << "na tom este musime popracovat !" << endl;
		ClientTCP client("192.168.31.160", 54000, Listener_MessageReceived_Client);
		if (client.Init()) {
			client.ConnectToServer();
		}
	}


	

}


void Listener_MessageReceived_Server(serverTCP* listener, int client, string msg) 
{
	listener->Send(client, msg);
	listener->PrintMessage(msg);
}

void Listener_MessageReceived_Client(ClientTCP* sender, int server, string msg) {
	//sender->Send(server, msg);
}