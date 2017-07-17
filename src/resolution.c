/*
** graphic.c for client in /home/loicpirez/CLionProjects/untitled/src
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Fri Jul 14 10:56:28 2017 Loïc Pirez
*/

#include <stdio.h>
#include <stdlib.h>
#include <resolution.h>
#include <error.h>
#include "strings.h"

t_resolution *get_current_resolution(void) {
    t_resolution *current_resolution;
    FILE *fp;
    char path[20];
    char *shell_command = "xdpyinfo | grep dimensions | sed -r 's/^[^0-9]*([0-9]+x[0-9]+).*$/\\1/'";
    int x, y = 0;

    if ((current_resolution = malloc(sizeof(t_resolution *))) == NULL)
        print_error_and_exit(ERROR_MALLOC, 84);
    if ((fp = popen(shell_command, "r")) == NULL)
        print_error_and_exit(ERROR_COMMAND, 84);
    while (fgets(path, sizeof(path) - 1, fp) != NULL);
    remove_char_from_string(path, '\n');
    if (sscanf(path, "%dx%d", &x, &y) != 2)
        print_error_and_exit(ERROR_RESFORMAT, 84);
    current_resolution->x = x;
    current_resolution->y = y;
    pclose(fp);
    return (current_resolution);
}
