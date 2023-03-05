#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
int main()
{
	int server_socket; //Var used in creating socket
	int client_socket; //Var used in accepting connection
	struct sockaddr_in server_addr; //Structure that `bind()` requires
	char buffer[500] = "[+++] Hello from the server!\n";
	char recv_buffer[500]; //Var for client input

	server_socket = socket(AF_INET, SOCK_STREAM, 0); //Create TCP Socket -- AF_NET: Ipv4, SOCK_STREAM: TCP

	server_addr.sin_family = AF_INET; //Declaring the type -- IPv4
	server_addr.sin_port = htons(****CHANGE_ME_TO_DESIRED_PORT****); // Declaring the port number to listen
	server_addr.sin_addr.s_addr = inet_addr("****CHANGE_ME_TO_DESIRED_IP****"); // Declaring the IP of the SERVER

	bind(server_socket, (struct server_addr*) &server_addr, sizeof(server_addr)); //binds a unique local name to the socket with descriptor socket
	listen(server_socket, 5); // Listening

	client_socket = accept(server_socket, NULL, NULL); // Accept incoming connection
	printf("[+++] Client has connected to the server!\n"); //Echo to screen when client connects
	send(client_socket, buffer, sizeof(buffer), 0); // Sending data to the client
	recv(client_socket, recv_buffer, sizeof(recv_buffer), 0); //Receive data from client
	printf("[+++] Client has sent: %s\n", recv_buffer); // Print data from the client
	close(server_socket);
	return 0;
}
