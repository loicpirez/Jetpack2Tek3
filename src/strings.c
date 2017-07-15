/*
** string.c for client in /home/loicpirez/CLionProjects/untitled/src
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Thu Jul 13 15:28:55 2017 Loïc Pirez
*/

#include <stdlib.h>
#include <ctype.h>
#include <error.h>
#include <stdio.h>

void remove_char_from_string(char *str, char to_skip) {
    int i = 0;
    int j = 0;

    while (str[i]) {
        if (str[i] != to_skip) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = 0;
}

size_t check_if_number(char *str, int error) {
    size_t nb;

    if (sscanf(str, "%zu", &nb) != 1)
        print_error_and_exit(error, 84);
    else
        return (nb);
    return (0);
}
