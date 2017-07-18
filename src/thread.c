/*
** thread.c for client in /home/loicpirez/CLionProjects/untitled/src
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Thu Jul 13 15:28:55 2017 Loïc Pirez
*/

#include <stdlib.h>
#include <pthread.h>
#include <error.h>
#include <args.h>
#include "graphical.h"
#include "network.h"
#include "get.h"

void *graphic_thread(void *arg)
{
    graphic((t_thread_data *) arg);
    return (NULL);
}

void *network_thread(void *arg)
{
    network((t_thread_data *) arg);
    return (NULL);
}

t_thread_data *create_thread(t_args *args, t_server_data *server_data)
{
    pthread_t pGraphic = 0;
    pthread_t pNetwork = 0;
    t_thread_data *thread_data;

    if ((thread_data = malloc(sizeof(t_thread_data))) == NULL)
    {
        print_error_and_exit(ERROR_MALLOC, 84);
    }
    thread_data->args = args;
    thread_data->server_data = server_data;
    get_first_informations(thread_data);
    if (pthread_create(&pGraphic, NULL, graphic_thread, thread_data) == -1 || \
        pthread_create(&pNetwork, NULL, network_thread, thread_data) == -1)
    {
        print_error_and_exit(ERROR_THREAD, 84);
    }
    pthread_join(pNetwork, NULL);
    pthread_join(pGraphic, NULL);
    return (thread_data);
}
