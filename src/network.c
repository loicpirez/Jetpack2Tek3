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
#include <error.h>
#include <unistd.h>
#include "args.h"
#include "network.h"

void network(t_thread_data *thread_data) {
    int sock;
    struct sockaddr_in server;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        print_error_and_exit(ERROR_SOCKET, 84);
    server.sin_addr.s_addr = inet_addr(thread_data->args->ip);
    server.sin_family = AF_INET;
    server.sin_port = htons((uint16_t) thread_data->args->port);
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0)
        print_error_and_exit(ERROR_CONNECT, 84);
    get_informations_from_server(sock, thread_data);
    close(sock);
}