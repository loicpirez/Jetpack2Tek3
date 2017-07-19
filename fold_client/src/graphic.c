/*
** graphic.c for client in /home/loicpirez/CLionProjects/untitled/src
** 
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
** 
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Tue Jul 18 21:10:06 2017 Loïc Pirez
*/

#include <SDL.h>
#include <args.h>
#include "ratio.h"
#include <network.h>
#include <graphical.h>
#include <error.h>
#include "calc.h"
#include "window.h"

void graphic(t_thread_data *thread_data)
{
  if (thread_data->server_data->id == 0)
    {
      while (thread_data->server_data->id == 0);
    }
  char title[25];
  sprintf(title, "jetpack2Tek3 [Player %d]", thread_data->server_data->id);
  SDL_Surface *window = NULL;
  t_resolution *res = get_current_resolution();
  t_resolution *ratio = calc_aspect_ratio((int) thread_data->server_data->mapX, (int) thread_data->server_data->mapY);
  t_resolution *target_resolution = calc_resolution_from_ratio(res, ratio);
  int block_size = calc_block_size(target_resolution, thread_data);

  window = SDL_SetVideoMode(target_resolution->x / 2, target_resolution->y / 2, 32, SDL_HWSURFACE);

  SDL_WM_SetCaption(title, NULL);

  if (window)
    {
      draw_window(window, thread_data, block_size);
    }
  else
    {
      print_error_and_exit(ERROR_SDL, 84);
    }
  free(res);
  free(ratio);
  free(target_resolution);
  exit(0);
}
