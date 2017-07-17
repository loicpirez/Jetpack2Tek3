/*
** array.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Mon Jul 17 15:33:02 2017 Loïc Pirez
** Last update Mon Jul 17 15:33:02 2017 Loïc Pirez
*/

#include <network.h>
#include <string.h>
#include <stdio.h>
#include <strings.h>
#include <malloc.h>
#include <error.h>

void print_array(char **array) {
    int i = 0;

    printf("Printing array...\n");
    while (array[i]) {
        printf("[%s], ", array[i]);
        i++;
    }
    printf("\n");
    fflush(0);
    printf("End of print\n");
}

int find_index(char **array, char *str) {
    int i = 0;

    while (array[i]) {
        if (strcmp(array[i], str) == 0)
            return (i);
        i++;
    }
    return (84);
}

int get_array_length(char **array) {
    int i = 0;

    while (array[i])
        i++;
    return (i);
}

char **split(char *str, char *token) {
    char **array;
    int i = 0;

    if ((array = malloc(BUFFER_SIZE * sizeof(char *) + (BUFFER_SIZE * (10 * sizeof(char))))) == NULL)
        print_error_and_exit(ERROR_MALLOC, 84);
    array[i] = strtok(str, token);
    while (array[i] != NULL) {
        ++i;
        array[i] = strtok(NULL, " \n");
    }
    i = 0;
    while (array[i]) {
        remove_char_from_string(array[i], '\n');
        i++;
    }
    return (array);
}