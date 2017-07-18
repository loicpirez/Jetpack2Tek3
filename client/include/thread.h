/*
** thread.h for threadal in /home/loicpirez/CLionProjects/untitled/include
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:23:35 2017 Loïc Pirez
** Last update Tue Jul 18 21:17:53 2017 Loïc Pirez
*/

#ifndef		THREAD_H_
# define	THREAD_H_

#include "args.h"

#include <pthread.h>

typedef struct s_thread_data
{
    t_args *args;
    t_server_data *server_data;
} t_thread_data;

t_thread_data *create_thread(t_args *args, t_server_data *server_data);

#endif        /* !THREAD_H_ */

