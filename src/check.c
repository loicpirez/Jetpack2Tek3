/*
** check_map.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Sat Jul 15 17:37:19 2017 Loïc Pirez
** Last update Sat Jul 15 17:37:19 2017 Loïc Pirez
*/

#include <printf.h>
#include <string.h>
#include <error.h>
#include <stdlib.h>
#include <network.h>
#include <strings.h>
#include <stdio.h>

void check_map(char *reply, t_thread_data *thread_data) {
    char *check;

    check = strtok(reply, " ");
    printf("[%s]\n", check);
    check = strtok(NULL, " ");
    printf("[%s]\n", check);
    if ((strcmp(check, "MAP")) != 0)
        print_error_and_exit(ERROR_MAPFORMAT, 84);

    if ((thread_data->server_data->raw_map = malloc(sizeof(char) + BUFFER_SIZE)) == NULL)
        print_error_and_exit(ERROR_MALLOC, 84);
    check = strtok(reply, " ");
    printf("[%s]\n", check);
    fflush(0);
    thread_data->server_data->mapX = check_if_number(check, ERROR_MAPFORMAT);
    check = strtok(NULL, " ");
    printf("[%s]\n", check);
    fflush(0);
    thread_data->server_data->mapY = check_if_number(check, ERROR_MAPFORMAT);
    check = strtok(NULL, " ");
    printf("[%s]\n", check);
    fflush(0);
    strcpy(thread_data->server_data->raw_map, check);
    remove_char_from_string(thread_data->server_data->raw_map, '\n');
    if (strlen(thread_data->server_data->raw_map) != thread_data->server_data->mapX * thread_data->server_data->mapY)
        print_error_and_exit(ERROR_MAPFORMAT, 84);
    free(reply);
}

void check_id(char *reply, t_thread_data *thread_data) {
    char *check;
    size_t id;

    check = strtok(reply, " \n");
    check = strtok(NULL, " \n");
    if (sscanf(check, "%zu\n", &id) != 1)
        print_error_and_exit(ERROR_MAPFORMAT, 84);
    thread_data->server_data->id = id;
}

void check_answer(char **answer) {
    int i = 0;

    while (answer[i]) {
        printf("[%s]\n", answer[i]);
        i++;
    }
}