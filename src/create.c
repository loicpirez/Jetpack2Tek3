/*
** create.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Sat Jul 15 17:48:24 2017 Loïc Pirez
** Last update Sat Jul 15 17:48:24 2017 Loïc Pirez
*/

#include <stdio.h>
#include <stdlib.h>
#include <network.h>
#include "error.h"
#include "args.h"

void init_map_array(t_thread_data *thread_data) {
    size_t x = 0;

    if ((thread_data->server_data->map = malloc(sizeof(char *) + thread_data->server_data->mapY + BUFFER_SIZE)) == NULL)
        print_error_and_exit(ERROR_MALLOC, 84);
    while (x != thread_data->server_data->mapX + 1) {
        if ((thread_data->server_data->map[x] = malloc(
                sizeof(char) + (thread_data->server_data->mapX + BUFFER_SIZE))) == NULL)
            print_error_and_exit(ERROR_MALLOC, 84);
        x++;
    }
    thread_data->server_data->map[x] = NULL;
}

void create_map(t_thread_data *thread_data) {
    size_t x = 0;
    size_t y = 0;
    size_t pos = 0;

    init_map_array(thread_data);
    while (pos != thread_data->server_data->mapX * thread_data->server_data->mapY) {
        if (pos % thread_data->server_data->mapY == 0 && pos != 0) {
            thread_data->server_data->map[y][x] = '\0';
            x = 0;
            y += 1;
        } else {
            thread_data->server_data->map[y][x] = thread_data->server_data->raw_map[pos];
        }
        pos++;
        x++;
    }
}