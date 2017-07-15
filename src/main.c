/*
** main.c for client in /home/loicpirez/CLionProjects/untitled/src
** 
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
** 
** Started on  Thu Jul 13 15:28:45 2017 Loïc Pirez
** Last update Thu Jul 13 15:28:46 2017 Loïc Pirez
*/

#include <SDL2/SDL.h>
#include <error.h>
#include <args.h>
#include "thread.h"
#include "server.h"

int main(int argc, char **argv) {
    t_args *args = get_args(argc, argv);
    t_server_data *server_data;

    if ((server_data = malloc(sizeof(t_server_data *))) == NULL)
        print_error_and_exit(ERROR_MALLOC, 84);
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        print_error_and_exit(ERROR_SDL, 84);
    else
        create_thread(args);
    free(args);
    free(server_data);
    SDL_Quit();
    return (0);
}
