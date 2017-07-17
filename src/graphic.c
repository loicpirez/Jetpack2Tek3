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
#include <zconf.h>
#include <network.h>
#include "resolution.h"

void graphic(t_thread_data *thread_data) {
    (void) thread_data;
    t_resolution *res = get_current_resolution();
    SDL_Window *pWindow = NULL;
    SDL_Event events;
    while (thread_data->server_data->is_ready != true);
    int block_size = (int) (res->x / thread_data->server_data->mapX);

    pWindow = SDL_CreateWindow("jetpack2Tek3", SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_UNDEFINED,
                               res->x / 2,
                               res->y / 2,
                               SDL_WINDOW_SHOWN);
    if (pWindow) {
        while (thread_data->server_data->is_finish != true) {
            SDL_PollEvent(&events);
            if (events.type == SDL_KEYDOWN) {
                ask_server(thread_data->server_data->sock, "FIRE 1\n");
            }
            else {
                ask_server(thread_data->server_data->sock, "FIRE 0\n");
            }
        }
        if (thread_data->server_data->winner == -1)
            printf("Nobody wins\n");
        else if (thread_data->server_data->winner == thread_data->server_data->id)
            printf("You win!\n");
        else
            printf("You loose!\n");
    } else
        print_error_and_exit(ERROR_SDL, 84);
    free(res);
}
