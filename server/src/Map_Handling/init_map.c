/*
** init_map.c for jetpack2Tek3_2016 in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/server/src/Map_Handling/init_map.c
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Sat Jul 15 15:08:50 2017 Valerian VERMEULEN
** Last update Sat Jul 15 15:08:50 2017 Valerian VERMEULEN
*/

#include	"Map_Func/init_map.h"

void		init_map(char *map, char *filename)
{
  size_t	size;
  char		*buff;
  FILE		*fd;

  size = 0;
  buff = NULL;
  fd = open_file(filename);
  while (getline(&buff, &size, fd) != -1)
  {
    map = strcat(map, buff);
    printf("%s\n", map);
  }
  fclose(fd);
  printf("Map : '%s'\n", map);
}