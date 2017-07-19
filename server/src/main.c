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

static void	init_and_launch(t_args *args)
{
  t_map		map;
  t_player	*player;

  player = malloc(sizeof(t_player) * 2);
  init_player(&player[0], args->gravity);
  init_player(&player[1], args->gravity);
  map = init_map(args->map_filename);
  launch_game(&map, player);
}

int		main(int ac, char **av)
{
  t_args	*args;

  args = malloc(sizeof(t_args));
  if (ac == 7)
  {
    args->error = check_arguments(args, ac, av);
    if (args->error == 1)
      dprintf(2, "Invalid arguments\n");
    else
      init_and_launch(args);
  }
  else
    dprintf(2, "Invalid arguments\n");
  return (0);
}