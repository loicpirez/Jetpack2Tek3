/*
** io.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Sat Jul 15 13:02:43 2017 Loïc Pirez
** Last update Tue Jul 18 21:10:09 2017 Loïc Pirez
*/

#include <sys/socket.h>
#include <string.h>
#include <display.h>
#include "error.h"

void ask_server(t_thread_data *thread_data, char *msg)
{
  int sock = thread_data->server_data->sock;
  if (thread_data->server_data->is_finish == 1)
    {
      display_winner_message(thread_data);
    }
  if (send(sock, msg, strlen(msg), MSG_DONTWAIT) < 0)
    {
      print_error_and_exit(ERROR_SEND, 84);
    }
}
