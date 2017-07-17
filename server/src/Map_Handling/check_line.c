/*
** check_line.c for server in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/server/src/Map_Handling/check_line.c
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Mon Jul 17 12:52:56 2017 Valerian VERMEULEN
** Last update Mon Jul 17 12:52:56 2017 Valerian VERMEULEN
*/

#include	"Map_Func/check_line.h"

int		check_line(char *buff)
{
  int		cpt;

  cpt = 0;
  while (buff[cpt] != 0)
  {
    if (strlen(buff) <= 1 || \
    	(buff[cpt] != '_' && buff[cpt] != 'e' && \
	buff[cpt] != 'c' && buff[cpt] != '\n'))
    {
      printf("Invalid map\n");
      return (-1);
    }
    cpt++;
  }
  return (0);
}