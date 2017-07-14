/*
** graphic.c for client in /home/loicpirez/CLionProjects/untitled/src
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Thu Jul 13 15:28:55 2017 Loïc Pirez
*/

#include <stdio.h>
#include <stdlib.h>
#include <resolution.h>
#include <string.h>

t_resolution *get_current_resolution(void) {
    t_resolution *current_resolution;
    FILE *fp;
    char path[1024];
    char *shell_command = \
    "xdpyinfo | grep dimensions | sed -r 's/^[^0-9]*([0-9]+x[0-9]+).*$/\\1/'";
    int x, y = 0;

    if ((current_resolution = malloc(sizeof(t_resolution *))) == NULL)
    {
        //todo exit
    }

    fp = popen(shell_command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1); //faire une command qui exit
    }
    while (fgets(path, sizeof(path)-1, fp) != NULL);
    remove_char_from_string(path, '\n');
    sscanf(path, "%dx%d", &x, &y) == 2 ? CORRECT_FORMAT: WRONG_FORMAT; //exit if wrongformat
    current_resolution->x = x;
    current_resolution->y = x;
    pclose(fp);
    return (current_resolution);
}
