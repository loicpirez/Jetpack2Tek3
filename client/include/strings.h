/*
** string.h for resolution in /home/loicpirez/CLionProjects/untitled/include
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:23:35 2017 Loïc Pirez
** Last update Tue Jul 18 21:17:51 2017 Loïc Pirez
*/

#ifndef		STRING_H_
# define	STRING_H_

# define	MAX_WORDS 12

#include <stdbool.h>

size_t check_if_number(char *str, int error);

void remove_char_from_string(char *input, char to_skip);

bool check_string_content(char *str, char *letter);

void reverse_string(char *str);

char *copy_string(const char *source);

#endif		/* !STRING_H_ */

