/*
** print_error_and_exit.c for client in /home/loicpirez/CLionProjects/untitled/src
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Thu Jul 13 15:28:55 2017 Loïc Pirez
*/

#include <error.h>
#include <stdio.h>
#include <stdlib.h>

void print_to_stderr(char *msg) {
    fprintf(stderr, msg);
}

void print_error_and_exit(int id, int status) {
    switch (id) {
        case ERROR_MALLOC:
            print_to_stderr("Can't perform memory allocation.\n");
        case ERROR_SDL:
            print_to_stderr("Can't initialize SDL.\n");
        case ERROR_COMMAND:
            print_to_stderr("Can't execute command.\n");
        case ERROR_IPFORMAT:
            print_to_stderr("Wrong format for given IP.\n");
        case ERROR_RESFORMAT:
            print_to_stderr("Wrong format for parsed resolution.\n");
        default:
            break;
    }
    exit(status);
}