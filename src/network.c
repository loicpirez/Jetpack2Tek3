/*
** network.c for client in /home/loicpirez/CLionProjects/untitled/src
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Thu Jul 13 15:28:55 2017 Loïc Pirez
*/

#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <error.h>
#include <check.h>
#include "network.h"
#include "array.h"

void network(t_thread_data *thread_data) {
    ssize_t status = 0;
    char **output = NULL;
    char *reply;

    ask_server(thread_data->server_data->sock, "ID\n");
    ask_server(thread_data->server_data->sock, "MAP\n");
    ask_server(thread_data->server_data->sock, "READY\n");
    if ((reply = malloc(sizeof(char) + BUFFER_SIZE)) == NULL)
        print_error_and_exit(ERROR_MALLOC, 84);
    while (true) {
        if ((status = recv(thread_data->server_data->sock, reply, BUFFER_SIZE, 0)) == -1)
            print_error_and_exit(ERROR_RECV, 84);
        else if (status != 0) {
            output = split(reply, " \n");
            check_answer(output, thread_data);
            if ((reply = malloc(sizeof(char) + BUFFER_SIZE)) == NULL)
                print_error_and_exit(ERROR_MALLOC, 84);
        } else if (strlen(reply) >= BUFFER_SIZE)
            print_error_and_exit(ERROR_BIGPACKET, 84);
        else
            break;
    }
    if (reply)
        free(reply);
    if (output)
        free(output);
}
