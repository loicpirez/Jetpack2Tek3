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
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <check.h>
#include "strings.h"
#include "args.h"
#include "network.h"

void get_id(int sock, t_thread_data *thread_data) {
    char *check;
    size_t id;

    check = ask_server(sock, "ID\n");
    if (sscanf(check, "ID %zu", &id) != 1)
        print_error_and_exit(ERROR_MAPFORMAT, 84);
    thread_data->server_data->id = id;
    //free(check);
}

void get_map(int sock, t_thread_data *thread_data) {
    char *reply;
    char *check;

    reply = ask_server(sock, "MAP\n");
    check = strtok(reply, " ");
    if ((strcmp(check, "MAP")) != 0)
        print_error_and_exit(ERROR_MAPFORMAT, 84);
    if ((thread_data->server_data->raw_map = malloc(sizeof(char) + BUFFER_SIZE)) == NULL)
        print_error_and_exit(ERROR_MALLOC, 84);
    check = strtok(NULL, " ");
    thread_data->server_data->mapX = check_if_number(check, ERROR_MAPFORMAT);
    check = strtok(NULL, " ");
    thread_data->server_data->mapY = check_if_number(check, ERROR_MAPFORMAT);
    check = strtok(NULL, " ");
    thread_data->server_data->raw_map = check;
    remove_char_from_string(thread_data->server_data->raw_map, '\n');
    check_map(thread_data);
}

void get_informations_from_server(int sock, t_thread_data *thread_data) {
    get_id(sock, thread_data);
    get_map(sock, thread_data);
    create_map(thread_data);
}
