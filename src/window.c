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

void
draw_map(SDL_Surface *window, SDL_Surface *coin, SDL_Surface *electric_wall, t_thread_data *thread_data, int block_size)
{
    SDL_Rect position;
    char *tmp = thread_data->server_data->raw_map;
    int i = 0;
    size_t x = 0;
    size_t y = 0;
    SDL_FillRect(window, NULL, SDL_MapRGB(window->format, COLOR_B));

    position.x = 0;
    position.y = 0;
    while (tmp[i])
    {
        if (x == thread_data->server_data->mapX - 1)
        {
            x = 0;
            y++;
        }
        else
        {
            x++;
        }
        position.x = (Sint16) (x * block_size);
        position.y = (Sint16) (y * block_size);
        if (tmp[i] == 'e')
            SDL_BlitSurface(electric_wall, NULL, window, &position);
        else if (tmp[i] == 'c')
            SDL_BlitSurface(coin, NULL, window, &position);
        i++;
    }
}

void draw_player(SDL_Surface *window, SDL_Surface *player_one, SDL_Surface *player_two, t_thread_data *thread_data,
                 int block_size)
{
    SDL_Rect position_one;
    SDL_Rect position_two;

    position_one.x = (thread_data->server_data->player_one_x * block_size) + block_size;
    position_one.y = ((thread_data->server_data->mapY - thread_data->server_data->player_one_y) * block_size) - block_size;
    position_two.x = (thread_data->server_data->player_two_x * block_size) + block_size;
    position_two.y = ((thread_data->server_data->mapY - thread_data->server_data->player_two_y) * block_size) - block_size;
    SDL_BlitSurface(player_one, NULL, window, &position_one);
    SDL_BlitSurface(player_two, NULL, window, &position_two);
}

void draw_window(SDL_Surface *window, t_thread_data *thread_data, int block_size)
{
    SDL_Event event;
    SDL_Surface *coin;
    SDL_Surface *electric_wall;
    SDL_Surface *player_one;
    SDL_Surface *player_two;
    bool lock = false;

    coin = SDL_CreateRGBSurface(SDL_HWSURFACE, block_size, block_size, 32, 0, 0, 0, 0);
    electric_wall = SDL_CreateRGBSurface(SDL_HWSURFACE, block_size, block_size, 32, 0, 0, 0, 0);
    player_one = SDL_CreateRGBSurface(SDL_HWSURFACE, block_size, block_size, 32, 0, 0, 0, 0);
    player_two = SDL_CreateRGBSurface(SDL_HWSURFACE, block_size, block_size, 32, 0, 0, 0, 0);

    SDL_FillRect(coin, NULL, SDL_MapRGB(window->format, COLOR_C));
    SDL_FillRect(electric_wall, NULL, SDL_MapRGB(window->format, COLOR_E));
    SDL_FillRect(player_one, NULL, SDL_MapRGB(window->format, COLOR_P1));
    SDL_FillRect(player_two, NULL, SDL_MapRGB(window->format, COLOR_P2));

    while (thread_data->server_data->is_finish != true)
    {
        draw_map(window, coin, electric_wall, thread_data, block_size);
        draw_player(window, player_one, player_two, thread_data, block_size);
        SDL_PollEvent(&event);

        if (thread_data->server_data->is_finish == true || event.type == SDL_QUIT)
        {
            thread_data->server_data->is_finish = true;
            lock = true;
        }

        do_fire(event, thread_data);
        SDL_Flip(window);
        SDL_FillRect(window, NULL, 0x000000);
    }
    if (lock == true)
    {

    }
    display_winner_message(thread_data);
}
