/*
** network.c for client in /home/loicpirez/CLionProjects/untitled/src
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Thu Jul 13 15:28:55 2017 Loïc Pirez
*/

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <args.h>
#include <error.h>
#include <unistd.h>
#include "network.h"

void ask_server(int sock, char *msg) {
    char server_reply[2000];
    if (send(sock, msg, strlen(msg), 0) < 0)
        print_error_and_exit(ERROR_SEND, 84);
    if (recv(sock, server_reply, 2000, 0) < 0)
        print_error_and_exit(ERROR_RECV, 84);
    puts(server_reply);

}

void get_informations_from_server(int sock) {
    ask_server(sock, "ID\n");
    ask_server(sock, "MAP\n");
}

void network(t_args *args) {
    int sock;
    struct sockaddr_in server;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        print_error_and_exit(ERROR_SOCKET, 84);
    server.sin_addr.s_addr = inet_addr(args->ip);
    server.sin_family = AF_INET;
    server.sin_port = htons((uint16_t) args->port);
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0)
        print_error_and_exit(ERROR_CONNECT, 84);
    get_informations_from_server(sock);
    close(sock);
}