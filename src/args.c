/*
** args.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Fri Jul 14 13:17:42 2017 Loïc Pirez
** Last update Fri Jul 14 13:17:43 2017 Loïc Pirez
*/

#include "usage.h"
#include <getopt.h>
#include <stdlib.h>
#include <error.h>
#include <stdio.h>
#include <args.h>
#include <string.h>

void check_ip_format(char *ip) {
    int a,b,c,d;

    if (sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d) != 4)
        print_error_and_exit(ERROR_IPFORMAT, 84);
}

void check_port_format(char *port) {
    int p;

    if (sscanf(port, "%d", &p) != 1)
        print_error_and_exit(ERROR_PORTFORMAT, 84);
}

t_args *get_args(int argc, char **argv) {
    t_args *args;
    char *ip = NULL;
    char *port = NULL;
    int next_option;
    const char *const short_options = "h:p:";

    if ((args = malloc(sizeof(t_args))) == NULL)
        print_error_and_exit(ERROR_MALLOC, 84);
    if (argc == 1)
        print_usage(argv[0]);
    while (1) {
        next_option = getopt(argc, argv, short_options);
        if (next_option == -1)
            break;
        switch (next_option) {
            case 'h' :
                ip = optarg;
                break;
            case 'p' :
                port = optarg;
                break;
            default :
                print_usage(argv[0]);
        }
    }
    if (port == NULL || ip == NULL)
        print_error_and_exit(ERROR_MISSINGARGS, 84);
    if (strcmp(ip, "localhost") == 0)
        ip = "127.0.0.1";
    check_port_format(port);
    check_ip_format(ip);
    args->ip = ip;
    args->port = atoi(port);
    return (args);
}