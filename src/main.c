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
#include <args.h>
#include <signals.h>
#include <error.h>
#include <thread.h>
#include <free.h>

int main(int argc, char **argv) {
    t_args *args = get_args(argc, argv);
    t_server_data *server_data = init_server_data();
    t_thread_data *thread_data = NULL;

    signal(SIGINT, catch_signal);

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        print_error_and_exit(ERROR_SDL, 84);
    else
        thread_data = create_thread(args, server_data);
    SDL_Quit();
    free_structs(thread_data);
    return (0);
}
