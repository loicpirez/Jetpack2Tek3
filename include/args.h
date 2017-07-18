/*
** args.h for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Fri Jul 14 13:19:03 2017 Loïc Pirez
** Last update Fri Jul 14 13:19:03 2017 Loïc Pirez
*/

#ifndef		ARGS_H_
# define	ARGS_H_

#include "server_data.h"

typedef struct s_args {
    int port;
    char *ip;
}              t_args;

t_args *get_args(int argc, char **argv);

#endif		/* !ARGS_H_ */
