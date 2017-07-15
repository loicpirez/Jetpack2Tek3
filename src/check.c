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
#include "args.h"

void check_map(t_thread_data *thread_data) {
    if (strlen(thread_data->server_data->raw_map) != thread_data->server_data->mapX * thread_data->server_data->mapY)
        print_error_and_exit(ERROR_MAPFORMAT, 84);
}