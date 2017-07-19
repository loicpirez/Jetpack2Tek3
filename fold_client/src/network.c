/*
** network.c for client in /home/loicpirez/CLionProjects/untitled/src
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Wed Jul 19 17:31:40 2017 Loïc Pirez
*/

#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <error.h>
#include <check.h>
#include <display.h>
#include "array.h"

void network(t_thread_data *thread_data)
{
  ssize_t status = 0;
  char **output = NULL;
  char *reply;

  ask_server(thread_data, "ID\n");
  ask_server(thread_data, "MAP\n");
  ask_server(thread_data, "READY\n");
  if ((reply = malloc(sizeof(char) + BUFFER_SIZE)) == NULL)
    print_error_and_exit(ERROR_MALLOC, 84);
  while (thread_data->server_data->is_finish != true)
    {
      if ((status = recv(thread_data->server_data->sock, reply, BUFFER_SIZE, 0)) == -1)
	{
	  if (thread_data->server_data->is_finish == 1)
	    display_winner_message(thread_data);
	  print_error_and_exit(ERROR_RECV, 84);
	}
      else if (status != 0)
	{
	  output = split(reply, " \n");
	  check_answer(output, thread_data);
	  if ((reply = malloc(sizeof(char) + BUFFER_SIZE)) == NULL)
	    print_error_and_exit(ERROR_MALLOC, 84);
	}
      else if (strlen(reply) >= BUFFER_SIZE)
	print_error_and_exit(ERROR_BIGPACKET, 84);
      else
	break;
    }
}
