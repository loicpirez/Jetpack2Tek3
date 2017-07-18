/*
** free.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Sat Jul 15 22:54:01 2017 Loïc Pirez
** Last update Sat Jul 15 22:54:01 2017 Loïc Pirez
*/

#include <stdlib.h>
#include "thread.h"

void free_structs(t_thread_data *thread_data)
{
    if (thread_data->server_data)
    {
        free(thread_data->server_data);
    }
    if (thread_data->args)
    {
        free(thread_data->args);
    }
    free(thread_data);
    exit(0);
}