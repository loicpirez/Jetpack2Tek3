/*
** create_socket.c for server in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/server/src/Sock_Handling/create_socket.c
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Wed Jul 19 08:30:43 2017 Valerian VERMEULEN
** Last update Wed Jul 19 08:30:43 2017 Valerian VERMEULEN
*/

#include	"Sock_Func/create_socket.h"

void		create_socket(int *fd, int port)
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;

  pe = getprotobyname("TCP");
  if (!pe)
    exit(84);
  *fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (*fd == -1)
    exit(84);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons((uint16_t)port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(*fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
  {
    close(*fd);
    exit(84);
  }
  if (listen(*fd, 42) == -1)
  {
    close(*fd);
    exit(84);
  }
}