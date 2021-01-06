#pragma once
#include <WS2tcpip.h>
#include <string>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")


//Forward declaration
class serverTCP;


//TO DO .. callback to data reciever
typedef void(*MessageReceivedHandler_S)(serverTCP* listener, int sockedId, std::string msg);
#define MAX_BUFFER_SIZE (49152)



class serverTCP
{

public:

	serverTCP(std::string ipAddress, int port, MessageReceivedHandler_S handler);
	~serverTCP();

	//send masage to the specified client
	void Send(int clientSocket, std::string msg);
	//inicialization winsock
	bool Init();

	// the main proccesing loop
	void Run();

	void CleanUp();

	void PrintMessage(std::string data);

private:	

	//create Socket;
	SOCKET CreateSocket();

	//wait for connection
	SOCKET WaitForConnection(SOCKET listening);


	std::string	m_ipAddress;
	int	m_port;
	MessageReceivedHandler_S MessageReceived;
	
};
