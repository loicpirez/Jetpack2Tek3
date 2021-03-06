/*
** print_error_and_exit.c for client in /home/loicpirez/CLionProjects/untitled/src
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Tue Jul 18 21:09:25 2017 Loïc Pirez
*/

#include <error.h>
#include <stdio.h>
#include <stdlib.h>

void print_to_stderr(char *msg)
{
  fprintf(stderr, "%s", msg);
  fflush(0);
}

void print_error_and_exit(int id, int status)
{
  if (id == ERROR_MALLOC)
    print_to_stderr("Can't perform memory allocation.\n");
  if (id == ERROR_SDL)
    print_to_stderr("Can't initialize SDL.\n");
  if (id == ERROR_COMMAND)
    print_to_stderr("Can't execute command.\n");
  if (id == ERROR_PORTFORMAT)
    print_to_stderr("Wrong format for given port.\n");
  if (id == ERROR_IPFORMAT)
    print_to_stderr("Wrong format for given IP.\n");
  if (id == ERROR_RESFORMAT)
    print_to_stderr("Wrong format for parsed resolution.\n");
  if (id == ERROR_MISSINGARGS)
    print_to_stderr("An argument is missing.\n");
  if (id == ERROR_SOCKET)
    print_to_stderr("Can't create socket.\n");
  if (id == ERROR_CONNECT)
    print_to_stderr("Can't connect() to specified IP and Port.\n");
  if (id == ERROR_SEND)
    print_to_stderr("Can't send() data to server.\n");
  if (id == ERROR_RECV)
    print_to_stderr("Can't recv() data to server.\n");
  if (id == ERROR_FD)
    print_to_stderr("Can't recv() on given fd.\n");
  if (id == ERROR_BIGPACKET)
    print_to_stderr("Packet is to big to handle.\n");
  if (id == ERROR_IDFORMAT)
    print_to_stderr("Wrong format received for server (ID).\n");
  if (id == ERROR_MAPFORMAT)
    print_to_stderr("Wrong format received for server (MAP).\n");
  if (id == ERROR_PLAYERFORMAT)
    print_to_stderr("Wrong format received for server (Player).\n");
  if (id == ERROR_COINFORMAT)
    print_to_stderr("Wrong format received for server (Coin).\n");
  if (id == ERROR_ENDFORMAT)
    print_to_stderr("Wrong format received for server (Finish).\n");
  exit(status);
}
