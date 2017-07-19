/*
** check_arguments.c for server in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/server/src/check_arguments.c
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Tue Jul 18 08:55:37 2017 Valerian VERMEULEN
** Last update Tue Jul 18 08:55:37 2017 Valerian VERMEULEN
*/

#include	"check_arguments.h"

static void	init_args(t_args *args)
{
  args->error = 0;
  args->port = 0;
  args->gravity = 0;
  args->map_filename = NULL;
}

static int	err_args(t_args *args)
{
  if (args->port == 0 || args->gravity == 0 || args->map_filename == NULL)
    return (1);
  return (0);
}

int		check_arguments(t_args *args, int ac, char **av)
{
  int		cpt;
  char		*error;

  cpt = 1;
  error = NULL;
  init_args(args);
  while (cpt < ac)
  {
    if (cpt % 2 && av[cpt+1][0] == '-')
      args->error = 1;
    if (strcmp(av[cpt], "-p") == 0)
      args->port = strtol(av[cpt+1], &error, 10);
    if (strcmp(av[cpt], "-m") == 0)
      args->map_filename = strdup(av[cpt+1]);
    if (strcmp(av[cpt], "-g") == 0)
      args->gravity = strtol(av[cpt+1], &error, 10);
    cpt++;
  }
  if (error != NULL)
    if (strlen(error) != 0 || err_args(args) == 1)
      args->error = 1;
  return (args->error);
}