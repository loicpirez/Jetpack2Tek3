/*
** graphic.c for client in /home/loicpirez/CLionProjects/untitled/src
** 
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
** 
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Thu Jul 13 15:28:55 2017 Loïc Pirez
*/

#include <SDL2/SDL.h>
#include <error.h>
#include <args.h>
#include "resolution.h"

void graphic(t_thread_data *thread_data) {
    t_resolution *res = get_current_resolution();
    SDL_Window *pWindow = NULL;

    pWindow = SDL_CreateWindow("jetpack2Tek3", SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_UNDEFINED,
                               res->x,
                               res->y,
                               SDL_WINDOW_SHOWN);
    if (pWindow) {
        SDL_DestroyWindow(pWindow);
    }
    else
        print_error_and_exit(ERROR_SDL, 84);
    free(res);
}
