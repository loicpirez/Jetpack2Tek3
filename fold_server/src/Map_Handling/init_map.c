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

static void	check_valid_map(t_map *map)
{
  int		cpt;
  size_t	len;

  cpt = 0;
  while (map->map[cpt] != NULL)
  {
    len = strlen(map->map[cpt]);
    if (map->map[cpt+1] != NULL)
      len--;
    if (len != map->width)
    {
      dprintf(2, "Invalid map\n");
      exit(0);
    }
    cpt++;
  }
}

t_map		init_map(char *filename)
{
  size_t	cpt;
  size_t	size;
  char		*buff;
  FILE		*fd;
  t_map		map;

  cpt = 0;
  size = 0;
  buff = NULL;
  map.map = NULL;
  fd = open_file(filename);
  while (getline(&buff, &size, fd) != -1)
  {
    if (check_line(buff) == 0)
      add_line(&map, buff, cpt);
    else
      exit(0);
    cpt++;
  }
  map.height = cpt;
  map.width = strlen(map.map[0]) - 1;
  map.map[cpt] = NULL;
  check_valid_map(&map);
  fclose(fd);
  return (map);
}