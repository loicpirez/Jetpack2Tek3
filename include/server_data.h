/*
** init_server_data.h for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Sat Jul 15 22:35:14 2017 Loïc Pirez
** Last update Sat Jul 15 22:35:14 2017 Loïc Pirez
*/

#ifndef		INIT_SERVER_DATA_H_
# define	INIT_SERVER_DATA_H_

#include <stddef.h>
#include <stdbool.h>

typedef struct s_server_data {
    int id;
    size_t mapX;
    size_t mapY;
    char *raw_map;
    bool is_ready;
    bool got_id;
    bool got_map;
    float player_one_x;
    float player_one_y;
    int player_one_points;
    float player_two_x;
    float player_two_y;
    int player_two_points;
    int sock;
    bool is_finish;
    int winner;
}              t_server_data;

t_server_data *init_server_data(void);

#endif		/* !INIT_SERVER_DATA_H_ */

