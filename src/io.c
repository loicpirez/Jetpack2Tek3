/*
** io.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Sat Jul 15 13:02:43 2017 Loïc Pirez
** Last update Sat Jul 15 13:02:44 2017 Loïc Pirez
*/

#include <sys/socket.h>
#include "network.h"
#include "error.h"

void ask_server(int sock, char *msg) {
    char server_reply[2000];
    if (send(sock, msg, strlen(msg), 0) < 0)
        print_error_and_exit(ERROR_SEND, 84);
    if (recv(sock, server_reply, 2000, 0) < 0)
        print_error_and_exit(ERROR_RECV, 84);
    //puts(server_reply);
}
