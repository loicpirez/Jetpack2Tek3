/*
** get.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Sat Jul 15 13:02:49 2017 Loïc Pirez
** Last update Sat Jul 15 13:02:49 2017 Loïc Pirez
*/

#include "args.h"
#include "network.h"

void get_informations_from_server(int sock, t_thread_data *thread_data) {
    ask_server(sock, "ID\n");
//    ask_server(sock, "MAP\n");
    (void)thread_data;
}
