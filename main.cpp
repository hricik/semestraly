#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include <fstream>
#pragma warning(disable : 4996)
#include "biznisLogika.h"
#include "HraciePole.h"

#pragma comment (lib, "ws2_32.lib")


struct Paket {
	int x, y, dlzka;
	char* spr;
};


using namespace std;

//void Listener_MessageReceived_Server(serverTCP* listener, int client, string msg);

//void Listener_MessageReceived_Client(ClientTCP* sender, int server, string msg);

string nastavIP() {
	string ip;
	cout << "Zadaj IP ADRESU SERVERA !";
	cin >> ip;
	return ip;
}

void main()
{
	//HraciePole hra;
	//hra.vytvorPrazdneHraciePole();
	biznisLogika pole;
	pole.print();

	cout << "Vitaj v hre lodicky! Pre vyber z moznosti napis cislo!" << endl;
	cout << "#######################################################################" << endl;
	cout << "1 - Server" << endl;
	cout << "2 - Client" << endl;
	cout << "3 - Navody" << endl;
	cout << "4 - pravidla hry" << endl;
	cout << "#######################################################################" << endl;


	int n = 0;
	cin >> n;
	switch (n)
	{
	case 1:
	{
		cout << "Zacina sa hra! Vytvaram server!" << endl;

		//inicializacia winsocketu;
		WSAData data;
		WORD ver = MAKEWORD(2, 2);
		int winsock = WSAStartup(ver, &data);

		if (winsock != 0) {
			cerr << "### Chyba pri inicializacii SOCKETU!" << endl;
			return;
		}

		//Vytvorenie socketu

		SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
		if (listening == INVALID_SOCKET) {
			cerr << "### Chyba pri vytvarani socketu!!!" << endl;
		}

		//bindovanie IP adresy a portu k socketu!

		sockaddr_in hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(54000); //  NASTAVENIE PORTU
		hint.sin_addr.S_un.S_addr = INADDR_ANY;

		bind(listening, (sockaddr*)&hint, sizeof(hint));

		listen(listening, SOMAXCONN);

		//vytvorenie socketu pre klienta a cakanie na pripojenie 

		sockaddr_in client;
		int clientSize = sizeof(client);

		SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

		char host_name[NI_MAXHOST];			// názov vzdialeného klienta
		char port[NI_MAXHOST];				// port vzdialeneho klienta

		ZeroMemory(host_name, sizeof(host_name));
		ZeroMemory(port, sizeof(port));

		if (getnameinfo((sockaddr*)&client, sizeof(client), host_name, sizeof(host_name), port, sizeof(port), 0)) {
			cout << "Klient je pripojeny na porte : " << port << endl;

		}
		else
		{
			inet_ntop(AF_INET, &client.sin_addr, host_name, NI_MAXHOST);
			cout << host_name << " connected on port" <<
				htons(client.sin_port) << endl;
		}
		//zatvorit listening socket
		closesocket(listening);
		cout << "Server VYTVORENY !!!" << endl << "Cakam na hraca" << endl;

		biznisLogika nepriat_h_pole;
		char buffer[sizeof(Paket)];
		nepriat_h_pole.print();

		while (true)
		{
			ZeroMemory(buffer, sizeof(Paket));

			// Wait for client to send data
			int bytesRecieved = recv(clientSocket, buffer, sizeof(Paket), 0);
			if (bytesRecieved == SOCKET_ERROR)
			{
				cerr << "Error pri recv(). UKONCUJEM!!!!" << endl;
				break;
			}

			if (bytesRecieved == 0)
			{
				cout << "client disconnected " << endl;
				break;
			}

			Paket* msgrcv = reinterpret_cast<Paket*>(buffer);
			string odpov = nepriat_h_pole.nastavPolohuSuradnic(msgrcv->x, msgrcv->y);

			cout << "Hrac poslal tieto suradnice >: X :" << msgrcv->x << ", Y :" << msgrcv->y << endl;
			std::cout << "vysledok hraca, ktory poslal suradnice je : " << odpov <<endl;


			Paket packet;
			char response_ptr[sizeof(odpov) + 1];
			strcpy(response_ptr, odpov.c_str());
			packet.spr = response_ptr;
			packet.dlzka = odpov.length();


			cout << endl;
			cout << endl;
			cout <<"Vloz suradnipe X (stlac enter) Y (stlac enter)"<< endl;
			std::cin >> packet.x >> packet.y;

			char* tmp = reinterpret_cast<char*>(&packet); // problem? 
			cout << "tu sa vytvara packet pre klienta v pakete je " << packet.x << " "<<packet.y << endl;
			int sendResult = send(clientSocket, tmp, sizeof(packet) + 1, 0);
			if (sendResult != SOCKET_ERROR)
			{
				std::cout << "Hracov tah >>>" << std::endl;

			}
		}

		//zatvorenie socketu;
		closesocket(clientSocket);
		//precistenie winsocketu
		WSACleanup();

		break;
	}
	case 2:
	{
		cout << "Zacina sa hra! Chystam sa pripojit na server!" << endl;

		//string ipaddresa = nastavIP();
		string ipaddresa = "192.168.31.160";
		int port_C = 54000;
		cout << "halo";

		//inicializacia winsocketu;
		WSAData data;
		WORD ver = MAKEWORD(2, 2);
		int wsResult = WSAStartup(ver, &data);
		if (wsResult != 0) {
			std::cout << "Cannot start wisock. Erro #" << wsResult << std::endl;
		}

		//Vytvorenie socketu;
		SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock == INVALID_SOCKET) {
			std::cout << "Cannot create socket. Erro #" << WSAGetLastError() << std::endl;
			WSACleanup();
			return;
		}

		//Vyplnenie štruktúry nápovedy, aby  winsocku vedel ku ktoremu portu sa ma pripojit
		sockaddr_in hint = { AF_INET,htons(port_C) };
		inet_pton(AF_INET, ipaddresa.c_str(), &hint.sin_addr);

		//PRIPOJENIE K serveru
		int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
		if (connResult == SOCKET_ERROR) {
			std::cout << "Cannot create socket. Erro #" << WSAGetLastError() << std::endl;
			closesocket(sock);
			WSACleanup();
			return;
		}

		//4.POSIELANIE A DOSTAVANIE INFORMACII
		char buffer[sizeof(Paket)];
		Paket msg;
		
		biznisLogika nepriatel;

		nepriatel.print();
		


		do {
			

			cout<< "Vloz suradnipe X (stlac enter) Y (stlac enter) "<< endl;
			cin >> msg.x;
			cin	>> msg.y;
			cout << "poslal si X "<<msg.x<< "Y " << msg.y << endl;
			if ((msg.x >= 0 && msg.y >= 0) && (msg.x < 16 && msg.y <16)){
				//Poslanie packetu s informaciami

				char* tmp = reinterpret_cast<char*>(&msg); // problem? 
				int sendResult = send(sock, tmp, sizeof(Paket) + 1, 0);

				if (sendResult != SOCKET_ERROR)
				{
					//Cakanie na odpoved;
					ZeroMemory(buffer, sizeof(Paket));
					int bytesReceived = recv(sock, buffer, sizeof(Paket), 0);
					Paket* vysledok = reinterpret_cast<Paket*>(buffer);
					if (bytesReceived > 0) {

						cout << "Hrac poslal tieto suradnice >: X : " << vysledok->x << ", Y : " << vysledok->y << endl;
						//cout << "Result on Player board: " << endl;
						cout << "od hraca ktory ti poslal udaje sa stal tento vysledok : " << nepriatel.nastavPolohuSuradnic(vysledok->x, vysledok->y) << endl;

					}
				}

			}
			else {
				cout << "packet values is x" << msg.x << " y " << msg.y << " dlzka" << msg.dlzka << endl;
			}
		} while (msg.x > 0 && msg.y > 0);
		cout << "zadal si 0 0 " << endl;
		//Odpojenie a precistenie winsocketu
		closesocket(sock);
		WSACleanup();




		break;
	}
	case 3:
		cout << "TU BUDE NAVOD HRY" << endl;

	case 4:

		cout << "TU BUDU PRAVIDLA HRY" << endl;

	default:

		break;
	}


	/*

	if (n == 1) {
			cout << "server is starting!" << endl;
		serverTCP server("192.168.31.164", 54000, Listener_MessageReceived_Server);

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
		*/


}






/*void Listener_MessageReceived_Server(serverTCP* listener, int client, string msg)
{
	listener->Send(client, msg);
	listener->PrintMessage(msg);
}

void Listener_MessageReceived_Client(ClientTCP* sender, int server, string msg) {
	sender->Send(server, msg);
}
*/
/*
void zapisDoSuboru(string n1, string n2, string n3) {
	ofstream myfile("výsledky.txt");
	if (myfile.is_open())
	{
		myfile << "Vitajete v zápise výsledku hry BATTLE SHIPS\n";
		myfile << "Výazom zápasu medzi hráèin "+n1+" a "+n2+" sa stáva hráè "+n3+".\n";
		myfile << "Gratulujem k výazstvu "+n3+" .\n";
		myfile.close();
		myfile << "----------------------------------------------.\n";
	}
	else cout << "Nepodarilo sa otvori súbor na zápis výsledkou!";
	
}
*/