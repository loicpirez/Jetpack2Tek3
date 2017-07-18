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
#include <args.h>
#include "ratio.h"
#include <network.h>
#include <graphical.h>
#include <error.h>
#include "calc.h"


void display_winner_message(t_thread_data *thread_data)
{
    pthread_mutex_lock(&thread_data->locker);
    if (thread_data->server_data->winner == -1)
    {
        printf("Nobody wins\n");
    }
    else if (thread_data->server_data->winner == thread_data->server_data->id)
    {
        printf("You win!\n");
    }
    else
    {
        printf("You loose!\n");
    }
    pthread_mutex_unlock(&thread_data->locker);
}

void draw_window(SDL_Window *window, t_thread_data *thread_data)
{
    SDL_Renderer *background_renderer = NULL;
    SDL_Renderer *coin_renderer = NULL;
    SDL_Event events;

    background_renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(background_renderer, COLOR_B);
    coin_renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(coin_renderer, COLOR_C);

    while (thread_data->server_data->is_finish != true)
    {
        pthread_mutex_lock(&thread_data->locker);
        if (thread_data->server_data->is_finish == true)
        {
            break;
        }
        pthread_mutex_unlock(&thread_data->locker);
        SDL_RenderClear(background_renderer);
        SDL_RenderClear(coin_renderer);

        SDL_PollEvent(&events);
        pthread_mutex_lock(&thread_data->locker);
        if (events.type == SDL_KEYDOWN)
        {
            ask_server(thread_data->server_data->sock, "FIRE 1\n");
        }
        else
        {
            ask_server(thread_data->server_data->sock, "FIRE 0\n");
        }
        pthread_mutex_unlock(&thread_data->locker);
        SDL_RenderPresent(background_renderer);
        SDL_RenderPresent(coin_renderer);
    }
    display_winner_message(thread_data);
}

void graphic(t_thread_data *thread_data)
{
    while (thread_data->server_data->is_ready != true);

    SDL_Window *window = NULL;

    t_resolution *res = get_current_resolution();
    t_resolution *ratio = calc_aspect_ratio((int) thread_data->server_data->mapX, (int) thread_data->server_data->mapY);
    t_resolution *target_resolution = calc_resolution_from_ratio(res, ratio);
    int block_size = calc_block_size(target_resolution, thread_data);
    (void)block_size; //TODO

    window = SDL_CreateWindow(
            "jetpack2Tek3", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_UNDEFINED,
            target_resolution->x / 2,
            target_resolution->y / 2,
            SDL_WINDOW_SHOWN
    );

    if (window)
    {
        draw_window(window, thread_data);
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
