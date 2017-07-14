/*
** print_error_and_exit.c for client in /home/loicpirez/CLionProjects/untitled/src
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Thu Jul 13 15:28:55 2017 Loïc Pirez
*/

#include <stdio.h>
#include <stdlib.h>

void print_error_and_exit(char *msg, int status)
{
    fprintf(stderr, msg);
    exit (status);
}