/*
** launch_game.h for server in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/server/inc/launch_game.h
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Wed Jul 19 07:27:20 2017 Valerian VERMEULEN
** Last update Wed Jul 19 07:27:20 2017 Valerian VERMEULEN
*/

#ifndef		SERVER_LAUNCH_GAME_H
# define	SERVER_LAUNCH_GAME_H

# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<unistd.h>
# include	"Map_Func/init_map.h"
# include	"Player_Func/init_player.h"

void		create_socket(int *fd, const int port);

void		change_gravity(t_player *player);
void		update_game(t_map *map, t_player *players);
int		check_winner(t_player *players);
int		check_score(t_player *players);

#endif		//SERVER_LAUNCH_GAME_H
