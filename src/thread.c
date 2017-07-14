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

void *graphic_thread(void *arg) {
    graphic();
    (void)arg;
    return (NULL);
}

void *network_thread(void *arg) {
    network((t_args *)arg);
    return (NULL);
}

void create_thread(t_args *args) {
    pthread_t pGraphic;
    pthread_t pNetwork;

    if (pthread_create(&pGraphic, NULL, graphic_thread, NULL) == -1 || \
        pthread_create(&pNetwork, NULL, network_thread, args) == -1)
        print_error_and_exit(ERROR_THREAD, 84);
    pthread_join(pNetwork, NULL);
    pthread_join(pGraphic, NULL);
}