/*
** signal.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Mon Jul 17 15:17:26 2017 Loïc Pirez
** Last update Mon Jul 17 15:17:26 2017 Loïc Pirez
*/

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void catch_signal(int signal)
{
    if (signal == SIGINT)
    {
        printf("\nCatched SIGINT. Aborting...\n");
        fflush(0);
        exit(0);
    }
}
