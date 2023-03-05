#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

int main()
{
	SOCKET client_socket; // Creates a SOCKET structure
	WSADATA wsastructure; // Creates a WSADATA structure required for WINSOCK initialization
	int result;
	struct sockaddr_in client_addr; // Creates a structure required by the connect()
	char sendData[500] = "[+++] Hello from the client!\n";
	char recvData[500];


	result = WSAStartup(MAKEWORD(2, 2), &wsastructure); // Initializing winsock
	if (result != 0)
	{
		printf("[!!!] Winsock initialization failed\n"); // Prints out error and exits with code 1
		return 1;
	}

	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(****CHANGE_ME_TO_DESIRED_PORT****);
	client_addr.sin_addr.s_addr = inet_addr("****CHANGE_ME_TO_DESIRED_IP****");

	connect(client_socket, (SOCKADDR*) &client_addr, sizeof(client_addr)); // Connect to the server
	recv(client_socket, recvData, sizeof(recvData), 0); // Receive data from server
	printf("[+++] Server says: %s\n", recvData); // Print data from server
	send(client_socket, sendData, sizeof(sendData), 0); //Send data to the server
	closesocket(client_socket); //Close thesocket  connection
	WSACleanup(); //Cleaning up
	return 0;
}
