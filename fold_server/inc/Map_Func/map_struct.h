/*
** map_struct.h for server in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/server/inc/Map_Func/map_struct.h
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Mon Jul 17 12:22:33 2017 Valerian VERMEULEN
** Last update Mon Jul 17 12:22:33 2017 Valerian VERMEULEN
*/

#ifndef		SERVER_MAP_STRUCT_H
# define	SERVER_MAP_STRUCT_H

typedef struct	s_map
{
  size_t	height;
  size_t	width;
  char		**map;
}		t_map;

#endif		//SERVER_MAP_STRUCT_H
