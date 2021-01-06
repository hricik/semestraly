#include "serverTCP.h"

serverTCP::serverTCP(std::string ipAddress, int port, MessageReceivedHandler_S handler)
	:m_ipAddress(ipAddress), m_port(port), MessageReceived(handler)
{

}
serverTCP::~serverTCP() 
{
	CleanUp();
}

//send masage to the specified client
void serverTCP::Send(int clientSocket, std::string msg) 
{
	send(clientSocket, msg.c_str(), msg.size() + 1, 0);

}
//inicialization winsock
bool serverTCP::Init() 
{
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsInit = WSAStartup(ver, &data);
	return wsInit == 0;
}

// the main proccesing loop
void serverTCP::Run() 
{
	char buff[MAX_BUFFER_SIZE];
	while (true) {
		//create to listening socket
		SOCKET listening = CreateSocket();
		if(listening == INVALID_SOCKET) {
			break;
		}
		SOCKET client = WaitForConnection(listening);
		if(client != INVALID_SOCKET) {
			closesocket(listening);
			int BytesReceived = 0;
			std::string message;
			do {
				
				std::getline(std::cin, message);
				if (message.size() > 0) 
				{
					Send(client, message);
				}
				ZeroMemory(buff, MAX_BUFFER_SIZE);
				BytesReceived = recv(client, buff,MAX_BUFFER_SIZE,0);
				if (BytesReceived > 0) {
					if (MessageReceived != NULL) {
						MessageReceived(this, client, std::string(buff, 0, BytesReceived));
						//PrintMessage(buff);
					}
				}
			} while (BytesReceived > 0);
			std::cout << "Client was disconnected !! " << std::endl;
			closesocket(client);
		}
	}

}

void serverTCP::CleanUp() 
{
	WSACleanup();
}

SOCKET serverTCP::CreateSocket() 
{
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening != INVALID_SOCKET) {
		sockaddr_in hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(m_port);
		inet_pton(AF_INET, m_ipAddress.c_str(), &hint.sin_addr);
		int bindOK = bind(listening, (sockaddr*)&hint, sizeof(hint));
		if (bindOK != SOCKET_ERROR) {
			int listenOK = listen(listening, SOMAXCONN);
			if (listenOK == SOCKET_ERROR) 
			{
				return -1;
			}
		}
		else {
			return -1;
		}
	}

	return listening;
}

void serverTCP::PrintMessage(std::string data) {

	std::cout <<"Klient odpoveda : "<< data << std::endl;

}

//wait for connection
SOCKET serverTCP::WaitForConnection(SOCKET listening) {
	SOCKET client = accept(listening, NULL, NULL);
	std::string msg = "serus ja som server";
	Send(client, msg);
	return client;
}


