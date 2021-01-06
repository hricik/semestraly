#pragma once

#include <WS2tcpip.h>
#include <string>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")


class ClientTCP;

typedef void(*MessageReceivedHandler_C)(ClientTCP* sender, int sockedId, std::string msg);
#define MAX_BUFFER_SIZE (49152)



class ClientTCP
{
public:
	ClientTCP(std::string ipAddress, int port, MessageReceivedHandler_C handler);
	
	//initialize WinSock
	bool Init();
	

	//fill in a hint structure

	//connect to server
	void ConnectToServer();
	// do-while loop to send an receive data
	void run();
	//gracefully close down everything
	~ClientTCP();

	void PrintMessage(char* data);

	void Send(int serverSocket, std::string msg);


private:


	//create socket
	SOCKET CreateSocket();

	std::string	m_ipAddress;
	int	m_port;
	MessageReceivedHandler_C MessageReceived;
	//hostent* server_name;

};

