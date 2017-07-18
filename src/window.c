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

void fill_surfaces(SDL_Surface *window, SDL_Surface *coin, SDL_Surface *electric_wall)
{
    SDL_FillRect(window, NULL, SDL_MapRGB(window->format, COLOR_B));
    SDL_FillRect(coin, NULL, SDL_MapRGB(window->format, COLOR_C));
    SDL_FillRect(electric_wall, NULL, SDL_MapRGB(window->format, COLOR_E));
}

void draw_map(SDL_Surface *window, SDL_Surface *coin, SDL_Surface *electric_wall, t_thread_data *thread_data, int block_size)
{
    SDL_Rect position;
    position.x = 0;
    position.y = 0;
    char *tmp = thread_data->server_data->raw_map;

    int i = 0; // x ----------
    size_t x = 0; //y ||||||||||
    size_t y = 0;

    while (tmp[i]) {
        putchar(tmp[i]);
        if (x == thread_data->server_data->mapX - 1)
        {
            putchar('\n');
            x = 0;
            y++;
        }
        else
        {
            x++;
        }
        position.x = (Sint16) (x * 20);
        position.y = (Sint16) (y * 20);
        if (tmp[i] == 'e')
            SDL_BlitSurface(electric_wall, NULL, window, &position);
        else if (tmp[i] == 'c')
            SDL_BlitSurface(coin, NULL, window, &position);
        i++;
    }
}

void draw_window(SDL_Surface *window, t_thread_data *thread_data, int block_size)
{
    SDL_Event event;
    SDL_Surface *coin;
    SDL_Surface *electric_wall;
    bool lock = false;

    coin = SDL_CreateRGBSurface(SDL_HWSURFACE, block_size, block_size, 32, 0, 0, 0, 0);
    electric_wall = SDL_CreateRGBSurface(SDL_HWSURFACE, block_size, block_size, 32, 0, 0, 0, 0);
    fill_surfaces(window, coin, electric_wall);
    draw_map(window, coin, electric_wall, thread_data, block_size);
    while (thread_data->server_data->is_finish != true)
    {
        SDL_PollEvent(&event);
        pthread_mutex_lock(&thread_data->locker);
        if (thread_data->server_data->is_finish == true || event.type == SDL_QUIT)
        {
            thread_data->server_data->is_finish = true;
            lock = true;
        }
        pthread_mutex_unlock(&thread_data->locker);
        do_fire(event, thread_data);

        SDL_Flip(window);
    }
    if (lock == true)
    {
        pthread_mutex_unlock(&thread_data->locker);
    }
    display_winner_message(thread_data);
}