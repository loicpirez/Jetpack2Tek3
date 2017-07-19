/*
** string.c for client in /home/loicpirez/CLionProjects/untitled/src
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Tue Jul 18 22:06:53 2017 Loïc Pirez
*/

#include <stdlib.h>
#include <error.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check_string_content(char *str, char *letter)
{
  int i = 0;
  int l = 0;
  bool okay = false;

  while (str[i])
    {
      okay = false;
      while (letter[l])
        {
	  if (str[i] == letter[l])
            {
	      okay = true;
            }
	  l++;
        }
      if (okay == false)
        {
	  return (false);
        }
      i++;
      l = 0;
    }
  return (true);
}

void remove_char_from_string(char *str, char to_skip)
{
  int i = 0;
  int j = 0;

  while (str[i])
    {
      if (str[i] != to_skip)
        {
	  str[j++] = str[i];
        }
      i++;
    }
  str[j] = 0;
}

char *copy_string(const char *source)
{
  char *copy;
  char *dest;
  int len = (int) strlen(source);

  if ((copy = malloc((size_t) (len + 1))) == NULL)
    print_error_and_exit(ERROR_MALLOC, 84);
  dest = copy;
  while (*source != '\0')
    {
      *dest++ = *source++;
    }
  *dest = '\0';
  return copy;
}

void reverse_string(char *str)
{
  if (str == 0)
    {
      return;
    }

  if (*str == 0)
    {
      return;
    }
  char *start = str;
  char *end = start + strlen(str) - 1;
  char temp;

  while (end > start)
    {
      temp = *start;
      *start = *end;
      *end = temp;
      ++start;
      --end;
    }
}


size_t check_if_number(char *str, int error)
{
  size_t nb;

  if (sscanf(str, "%zu", &nb) != 1)
    {
      print_error_and_exit(error, 84);
    }
  else
    {
      return (nb);
    }
  return (0);
}
