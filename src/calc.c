/*
** calc.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Tue Jul 18 13:07:12 2017 Loïc Pirez
** Last update Tue Jul 18 13:07:12 2017 Loïc Pirez
*/

#include "resolution.h"
#include "thread.h"

int calc_block_size(t_resolution *resolution, t_thread_data *thread_data)
{
    return (int) ((resolution->x / thread_data->server_data->mapX) / 2);
}
