/*
** event.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Tue Jul 18 13:32:42 2017 Loïc Pirez
** Last update Tue Jul 18 13:32:42 2017 Loïc Pirez
*/

#include <network.h>
#include "event.h"

void do_fire(SDL_Event event, t_thread_data *thread_data)
{
    if (event.type == SDL_KEYDOWN)
    {
        ask_server(thread_data, "FIRE 1\n");
    }
    else
    {
        ask_server(thread_data, "FIRE 0\n");
    }

}