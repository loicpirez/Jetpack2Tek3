/*
** get.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Sat Jul 15 13:02:49 2017 Loïc Pirez
** Last update Sat Jul 15 13:02:49 2017 Loïc Pirez
*/

#include <stdio.h>
#include <error.h>
#include <check.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void get_first_informations(t_thread_data *thread_data) {
    struct sockaddr_in server;

    if ((thread_data->server_data->sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        print_error_and_exit(ERROR_SOCKET, 84);
    server.sin_addr.s_addr = inet_addr(thread_data->args->ip);
    server.sin_family = AF_INET;
    server.sin_port = htons((uint16_t) thread_data->args->port);
    if (connect(thread_data->server_data->sock, (struct sockaddr *) &server, sizeof(server)) < 0)
        print_error_and_exit(ERROR_CONNECT, 84);
}
