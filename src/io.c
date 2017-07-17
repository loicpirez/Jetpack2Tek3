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
#include <malloc.h>
#include <string.h>
#include <strings.h>
#include "network.h"
#include "error.h"

void ask_server(int sock, char *msg) {
    if (send(sock, msg, strlen(msg), MSG_DONTWAIT) < 0)
        print_error_and_exit(ERROR_SEND, 84);
}
