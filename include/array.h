/*
** array.h for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Mon Jul 17 15:34:53 2017 Loïc Pirez
** Last update Mon Jul 17 15:34:53 2017 Loïc Pirez
*/
#ifndef        ARRAY_H_
# define    ARRAY_H_

#define INDEX_NOT_FOUND 84

char **split(char *str, char *token);

int get_array_length(char **array);

int find_index(char **array, char *str);

void print_array(char **array);

int count_occurencies(char **array, char *str);

#endif        /* !ARRAY_H_ */

