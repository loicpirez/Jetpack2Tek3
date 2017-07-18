/*
** init_server_data.h for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Sat Jul 15 22:35:14 2017 Loïc Pirez
** Last update Sat Jul 15 22:35:14 2017 Loïc Pirez
*/

#ifndef        INIT_SERVER_DATA_H_
# define    INIT_SERVER_DATA_H_

#include <stddef.h>
#include <stdbool.h>

typedef struct s_server_data
{
    int id;
    bool is_ready;
    bool is_finish;
    bool got_id;
    bool got_map;
    size_t mapX;
    size_t mapY;
    int player_one_points;
    float player_one_x;
    float player_one_y;
    int player_two_points;
    float player_two_x;
    float player_two_y;
    char *raw_map;
    int sock;
    int winner;
    int coin_x;
    int coin_y;
} t_server_data;

t_server_data *init_server_data(void);

#endif        /* !INIT_SERVER_DATA_H_ */

