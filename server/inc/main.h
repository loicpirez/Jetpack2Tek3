/*
** main.h for jetpack2Tek3_2016 in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/inc/main.h
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Fri Jul 14 08:56:33 2017 Valerian VERMEULEN
** Last update Fri Jul 14 08:56:33 2017 Valerian VERMEULEN
*/

#ifndef		JETPACK2TEK3_2016_MAIN_H
# define	JETPACK2TEK3_2016_MAIN_H

# include	<stdio.h>
# include	<stdlib.h>
# include	"Map_Func/map_struct.h"
# include	"Player_Func/player_struct.h"

t_map		init_map(char *filename);
void		init_player(t_player *player);

#endif		//JETPACK2TEK3_2016_MAIN_H