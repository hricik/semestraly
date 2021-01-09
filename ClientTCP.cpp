#include "ClientTCP.h"
#include <fstream>
#include <iostream>

using namespace std;
ClientTCP::ClientTCP(std::string ipAddress, int port, MessageReceivedHandler_C handler)
	:m_ipAddress(ipAddress), m_port(port), MessageReceived(handler)
{


}
bool ClientTCP::Init() {
	//server_name = gethostbyname("Klient");
	//	server_name->h_length;
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0) {

		std::cerr << "cant start winsock, error #" << wsResult << std::endl;
		return false;
	}

	return wsResult == 0;
}

ClientTCP::~ClientTCP() {
	WSACleanup();
}

SOCKET ClientTCP::CreateSocket() {
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0); //HEREEEEEE
	if (sock == INVALID_SOCKET) {
		std::cerr << " cant create socket, err #" << WSAGetLastError() << std::endl;
		WSACleanup();
		return NULL;
	}

	return sock;
}

void ClientTCP::ConnectToServer() {
	SOCKET socket = CreateSocket();
	if (socket == INVALID_SOCKET) {
		std::cerr << "hzmane" << std::endl;
	}
	//cout << "hymane" << endl;
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(m_port);
	std::cerr << "hzmane" << std::endl;
	inet_pton(AF_INET, m_ipAddress.c_str(), &hint.sin_addr);
	std::cerr << "hzmane" << std::endl;
	int connResult = connect(socket, (sockaddr*)&hint, sizeof(hint));
	cout << "hymaneee" << endl;
	if (connResult == SOCKET_ERROR) {
		std::cerr << " cant connect to server, err #" << WSAGetLastError() << std::endl;
		closesocket(socket);
		WSACleanup();
		return;
	}
	char buff[MAX_BUFFER_SIZE];
	std::string userInput = "masdasdadas";
	cout << "rontoto" << endl;
	do {
		cout << "> :";
		getline(cin, userInput);

		if (userInput.size() > 0) {
			int sendResult = send(socket, userInput.c_str(), userInput.size() + 1, 0);
			if (sendResult != SOCKET_ERROR) {
				ZeroMemory(buff, MAX_BUFFER_SIZE);
				int byteReceiver = recv(socket, buff, MAX_BUFFER_SIZE, 0);
				if (byteReceiver > 0) {
					if (MessageReceived != NULL) {
						MessageReceived(this, socket, string(buff, 0, byteReceiver));
						cout << "### SERVER ODPOVEDA ### >> " << string(buff, 0, byteReceiver) << endl;
					}
				}

			}
		}
	} while (userInput.size() > 0);
	//cout << "server neodpovedal nic. odpajam" << endl;
	closesocket(socket);
	WSACleanup();
}

void ClientTCP::Send(int serverSocket, string msg) {
	send(serverSocket, msg.c_str(), msg.size() + 1, 0);
}



void ClientTCP::PrintMessage(char* data) {
	std::cout << data << std::endl;
}

