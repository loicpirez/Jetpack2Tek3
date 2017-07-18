/*
** window.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Tue Jul 18 13:44:08 2017 Loïc Pirez
** Last update Tue Jul 18 13:44:13 2017 Loïc Pirez
*/

#include <graphical.h>
#include "display.h"
#include "event.h"

void draw_window(SDL_Window *window, t_thread_data *thread_data)
{
    SDL_Renderer *background_renderer = NULL;
    SDL_Event event;
    bool quit = false;

    background_renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(background_renderer, COLOR_B);

    while (thread_data->server_data->is_finish != true)
    {
        SDL_PollEvent(&event);
        pthread_mutex_lock(&thread_data->locker);
        if (thread_data->server_data->is_finish == true || event.type == SDL_QUIT ||
            (
                    event.type == SDL_WINDOWEVENT &&
                    event.window.event == SDL_WINDOWEVENT_CLOSE
            ))
        {
            thread_data->server_data->is_finish = true;
        }
        pthread_mutex_unlock(&thread_data->locker);
        do_fire(event, thread_data);
        SDL_RenderClear(background_renderer);
        SDL_RenderPresent(background_renderer);
    }
    display_winner_message(thread_data);
}
