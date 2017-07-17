/*
** add_line.c for server in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/server/src/Map_Handling/add_line.c
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Mon Jul 17 13:48:39 2017 Valerian VERMEULEN
** Last update Mon Jul 17 13:48:39 2017 Valerian VERMEULEN
*/

#include	"Map_Func/add_line.h"

void		add_line(t_map *map, char *buff, int cpt) 
{
  map->map = realloc(map->map, sizeof(char *) * (cpt + 2));
  if (map->map == NULL)
    exit (84);
  map->map[cpt] = malloc(sizeof(char));
  map->map[cpt][0] = 0;
  map->map[cpt] = strdup(buff);
  printf("%s\n", map->map[cpt]);
}