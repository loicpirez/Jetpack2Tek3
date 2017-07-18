/*
** display.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Tue Jul 18 13:30:39 2017 Loïc Pirez
** Last update Tue Jul 18 13:30:39 2017 Loïc Pirez
*/

#include <thread.h>
#include <stdio.h>

void display_winner_message(t_thread_data *thread_data)
{
    pthread_mutex_lock(&thread_data->locker);
    if (thread_data->server_data->winner == -1)
    {
        printf("Nobody wins\n");
    }
    else if (thread_data->server_data->winner == thread_data->server_data->id)
    {
        printf("You win!\n");
    }
    else
    {
        printf("You loose!\n");
    }
    fflush(0);
    pthread_mutex_unlock(&thread_data->locker);
}
