/*
** init_map.h for jetpack2Tek3_2016 in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/server/inc/Map_Functions_Headers/init_map.h
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Sat Jul 15 14:52:29 2017 Valerian VERMEULEN
** Last update Sat Jul 15 14:52:30 2017 Valerian VERMEULEN
*/

#ifndef		JETPACK2TEK3_2016_INIT_MAP_H
# define	JETPACK2TEK3_2016_INIT_MAP_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	"map_struct.h"

FILE		*open_file(char *filename);
int		check_line(char *buff);
void		add_line(t_map *map, char *buff, size_t cpt);

#endif		//JETPACK2TEK3_2016_INIT_MAP_H
