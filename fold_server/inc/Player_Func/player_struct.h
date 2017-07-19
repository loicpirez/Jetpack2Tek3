/*
** player_struct.h for jetpack2Tek3_2016 in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/server/inc/Player_Functions_Headers/player_struct.h
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Sat Jul 15 14:37:10 2017 Valerian VERMEULEN
** Last update Sat Jul 15 14:37:10 2017 Valerian VERMEULEN
*/

#ifndef		JETPACK2TEK3_2016_PLAYER_STRUCT_H
# define	JETPACK2TEK3_2016_PLAYER_STRUCT_H

typedef struct	s_player
{
  int		id;
  float		x;
  float		y;
  int		score;
  int		gravity;
}		t_player;

#endif		//JETPACK2TEK3_2016_PLAYER_STRUCT_H
