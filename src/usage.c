/*
** usage.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Fri Jul 14 13:34:02 2017 Loïc Pirez
** Last update Fri Jul 14 13:34:02 2017 Loïc Pirez
*/

#include <stdio.h>
#include <stdlib.h>

void print_usage(char *name)
{
    fprintf(stderr, "USAGE\n\t%s -h IP -p PORT\n", name);
    fprintf(stderr, "EXEMPLE\n\t%s -h 127.0.0.1 -p 4242\n", name);
    exit(84);
}