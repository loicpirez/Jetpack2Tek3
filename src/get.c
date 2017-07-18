/*
** get.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Sat Jul 15 13:02:49 2017 Loïc Pirez
** Last update Sat Jul 15 13:02:49 2017 Loïc Pirez
*/

#include <stdio.h>
#include <error.h>
#include <check.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

void get_first_informations(t_thread_data *thread_data)
{
    struct sockaddr_in server;

    if ((thread_data->server_data->sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        print_error_and_exit(ERROR_SOCKET, 84);
    }
    server.sin_addr.s_addr = inet_addr(thread_data->args->ip);
    server.sin_family = AF_INET;
    server.sin_port = htons((uint16_t) thread_data->args->port);
    if (connect(thread_data->server_data->sock, (struct sockaddr *) &server, sizeof(server)) < 0)
    {
        print_error_and_exit(ERROR_CONNECT, 84);
    }
}

void get_player_informations(char **answer, char *number, t_thread_data *thread_data)
{
    int i = 0;
    int playernb = atoi(number);
    float x;
    float y;
    int points;

    while (answer[i])
    {
        if ((strcmp(answer[i], "PLAYER") == 0) &&
            answer[i + 1] != NULL &&
            (strcmp(answer[i + 1], number) == 0))
        {
            if (answer[i + 2] && answer[i + 3] && answer[i + 4])
            {
                if (((sscanf(answer[i + 2], "%f", &x) == 1) != 1) || ((sscanf(answer[i + 3], "%f", &y) == 1) != 1) ||
                    ((sscanf(answer[i + 4], "%d", &points) == 1) != 1))
                {
                    print_error_and_exit(ERROR_PLAYERFORMAT, 84);
                }
                if (playernb == 1)
                {
                    thread_data->server_data->player_one_x = y;
                    thread_data->server_data->player_one_y = y;
                    thread_data->server_data->player_one_points = points;
                }
                if (playernb == 2)
                {
                    thread_data->server_data->player_two_x = y;
                    thread_data->server_data->player_two_y = y;
                    thread_data->server_data->player_two_points = points;
                }
                break;
            }
            else
            {
                print_error_and_exit(ERROR_PLAYERFORMAT, 84);
            }
        }
        i++;
    }
}
