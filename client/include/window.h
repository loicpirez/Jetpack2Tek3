/*
** window.h for window in /home/loicpirez/CLionProjects/untitled/include
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:23:35 2017 Loïc Pirez
** Last update Tue Jul 18 21:17:57 2017 Loïc Pirez
*/

#ifndef		WINDOW_H_
# define	WINDOW_H_

#include "SDL.h"
#include "network.h"

void draw_window(SDL_Surface *window, t_thread_data *thread_data, int block_size);

#endif		/* !WINDOW_H_ */

