/*
** args_struct.h for server in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/server/inc/args_struct.h
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Tue Jul 18 08:23:58 2017 Valerian VERMEULEN
** Last update Tue Jul 18 08:23:58 2017 Valerian VERMEULEN
*/

#ifndef		SERVER_ARGS_STRUCT_H
# define	SERVER_ARGS_STRUCT_H

typedef struct 	s_args
{
  int		error;
  int		port;
  int		gravity;
  char		*map_filename;
}		t_args;

#endif		//SERVER_ARGS_STRUCT_H
