/*
** main.c for jetpack2Tek3 in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016
** 
** Made by Valerian Vermeulen
** Login   <vermeu_v@epitech.net>
** 
** Started on  Fri Jul 14 10:53:06 2017 Valerian Vermeulen
** Last update Fri Jul 14 10:53:06 2017 Valerian Vermeulen
*/

#include	"main.h"

int		main(int ac, char **av)
{
  char		*map;
  t_player	**player;

  (void)ac;
  map = malloc(sizeof(char) * 1);
  map[0] = 0;
  player = malloc(sizeof(t_player *) * 2);
  init_player(player[0]);
  init_player(player[1]);
  init_map(map, av[1]);
  (void)player;
  (void)map;
  return (0);
}