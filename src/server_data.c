/*
** init_server_data.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Sat Jul 15 22:31:54 2017 Loïc Pirez
** Last update Sat Jul 15 22:31:54 2017 Loïc Pirez
*/

#include <stdlib.h>
#include <error.h>
#include <stdbool.h>
#include "server_data.h"

t_server_data *init_server_data(void) {
    t_server_data *server_data;

    if ((server_data = malloc(sizeof(t_server_data))) == NULL)
        print_error_and_exit(ERROR_MALLOC, 84);
    server_data->mapX = 0;
    server_data->mapY = 0;
    server_data->raw_map = 0;
    server_data->id = 0;
    server_data->is_ready = false;
    return (server_data);
}

