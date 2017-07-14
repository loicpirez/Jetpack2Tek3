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
#include "resolution.h"

void graphic() {
    get_current_resolution();
    SDL_Window *pWindow = NULL;

    pWindow = SDL_CreateWindow("Jetpack2Tek3", SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_UNDEFINED,
                               800,
                               600,
                               SDL_WINDOW_SHOWN);
    if (pWindow) {
        //TODO
        SDL_DestroyWindow(pWindow);
    } else {
        fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError()); //Create error fn
        exit (84);
    }
}
