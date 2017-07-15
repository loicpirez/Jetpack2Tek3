/*
** server.h for server in /home/loicpirez/CLionProjects/untitled/include
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:23:35 2017 Loïc Pirez
** Last update Thu Jul 13 15:23:41 2017 Loïc Pirez
*/

#ifndef		SERVER_H_
# define	SERVER_H_

#include <stddef.h>

typedef struct s_server_data {
    size_t id;
    size_t mapX;
    size_t mapY;
    char *raw_map;
}              t_server_data;

#endif		/* !SERVER_H_ */
