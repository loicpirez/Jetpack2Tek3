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
    fflush(0);
}

void print_error_and_exit(int id, int status) {
    switch (id) { //fn punters
        case ERROR_MALLOC:
            print_to_stderr("Can't perform memory allocation.\n");
            break;
        case ERROR_SDL:
            print_to_stderr("Can't initialize SDL.\n");
            break;
        case ERROR_COMMAND:
            print_to_stderr("Can't execute command.\n");
            break;
        case ERROR_PORTFORMAT:
            print_to_stderr("Wrong format for given port.\n");
            break;
        case ERROR_IPFORMAT:
            print_to_stderr("Wrong format for given IP.\n");
            break;
        case ERROR_RESFORMAT:
            print_to_stderr("Wrong format for parsed resolution.\n");
            break;
        case ERROR_MISSINGARGS:
            print_to_stderr("An argument is missing.\n");
            break;
        case ERROR_SOCKET:
            print_to_stderr("Can't create socket.\n");
            break;
        case ERROR_CONNECT:
            print_to_stderr("Can't connect() to specified IP and Port.\n");
            break;
        case ERROR_SEND:
            print_to_stderr("Can't send() data to server.\n");
            break;
        case ERROR_RECV:
            print_to_stderr("Can't recv() data to server.\n");
            break;
        default:
            break;
    }
    exit(status);
}