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
    size_t id;
    size_t mapX;
    size_t mapY;
    char *raw_map;
    char **map;
    bool is_ready;
}              t_server_data;

t_server_data *init_server_data(void);

#endif		/* !INIT_SERVER_DATA_H_ */

