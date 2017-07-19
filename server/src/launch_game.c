/*
** launch_game.c for server in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/server/src/launch_game.c
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Wed Jul 19 07:30:59 2017 Valerian VERMEULEN
** Last update Wed Jul 19 07:30:59 2017 Valerian VERMEULEN
*/

#include	"launch_game.h"

void		launch_game(t_map *map, t_player *players, int port)
{
  int		fd;

  create_socket(&fd, port);
  //accept client1
  //accept client2
  /* while (ready == 0)
   * {
   * 	select();
   * 	if (read fd, IP -> write fd, IP);
   * 	if (read fd, MAP -> write fd, MAP);
   * 	if (read fd, READY -> ready = 1);
   * }*/
  // write sans requete START
  /* while (done == 0)
   * {
   * 	select();
   * 	if (read requete FIRE)
   * 		change gravity;
   * 	write sans requete (PLAYER || COIN)
   * 	update en fonction de gravity
   * 	check winner (fd collision ou end)
   * 	if (end)
   * 		check_score
   * 	set winner fd
   * }*/
  // write FINISH winner fd
}