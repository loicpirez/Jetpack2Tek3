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
#include "thread.h"

int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return 84; //create_error_fn
    } else {
        create_thread();
    }
    SDL_Quit();
    return 0;
}
