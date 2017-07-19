/*
** init_player.c for server in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/server/src/Player_Handling/init_player.c
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Sat Jul 15 15:15:41 2017 Valerian VERMEULEN
** Last update Sat Jul 15 15:15:41 2017 Valerian VERMEULEN
*/

#include	"Player_Func/init_player.h"

void		init_player(t_player *player, int gravity)
{
  player = malloc(sizeof(t_player));
  if (player == NULL)
    exit(84);
  if (player == NULL)
    exit(84);
  player->id = 0;
  player->x = 0;
  player->y = 0;
  player->score = 0;
  player->gravity = gravity;
}