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

static void	get_ready(int fd, int *client_fds, \
				t_player *players, t_map *map)
{
  ssize_t		r;
  int			ready;
  fd_set		readfds;
  struct timeval	tv;
  char			buf[4096];

  tv.tv_sec = 0;
  tv.tv_usec = 200;
  ready = 0;
  printf("get ready\n");
  while (ready == 0)
  {
    printf("waiting...\n");
    FD_ZERO(&readfds);
    FD_SET(client_fds[0], &readfds);
    FD_SET(client_fds[1], &readfds);
    if (select(fd + 1, &readfds, NULL, NULL, &tv) == -1)
      exit(84);
    if (FD_ISSET(client_fds[0], &readfds))
    {
      r = read(client_fds[0], buf, 4096);
      buf[r] = 0;
      if (strcmp(buf, "ID") == 0)
	dprintf(client_fds[0], "ID %d\n", players[0].id);
    }
   //	if (read fd, MAP -> write fd, MAP);
   //	if (read fd, READY -> ready = 1);
  }
  // write sans requete START
  (void)map;
}

static void	play_game()
{
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

void		launch_game(t_map *map, t_player *players, int port)
{
  int			fd;
  int			client_fds[2];
  struct sockaddr_in	s_in_client;
  socklen_t 		s_in_size;

  s_in_size = sizeof(s_in_client);
  create_socket(&fd, port);
  client_fds[0] = accept(fd,(struct sockaddr *)&s_in_client, &s_in_size);
  client_fds[1] = accept(fd,(struct sockaddr *)&s_in_client, &s_in_size);
  printf("HOLO 1\n");
  if (client_fds[0] == -1 || client_fds[1] == -1)
  {
    printf("HOLO 2\n");
    close(fd);
    exit(84);
  }
  printf("HOLO 3\n");
  get_ready(fd, client_fds, players, map);
  play_game();
  if (close(client_fds[0]) == -1 || close(client_fds[1]) == -1 || \
  	close(fd) == -1)
    exit(84);
}