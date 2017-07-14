#include <printf.h>

/*
** string.c for client in /home/loicpirez/CLionProjects/untitled/src
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Thu Jul 13 15:28:55 2017 Loïc Pirez
*/

void remove_char_from_string(char *str, char to_skip) {
    int i = 0;
    int j = 0;

    while (str[i]) {
        if (str[i] != to_skip) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j]=0;
}