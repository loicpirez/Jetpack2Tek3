/*
** network.h for network in /home/loicpirez/CLionProjects/untitled/include
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:23:35 2017 Loïc Pirez
** Last update Tue Jul 18 21:17:41 2017 Loïc Pirez
*/

#ifndef		NETWORK_H_
# define	NETWORK_H_

# define	BUFFER_SIZE 8192

#include "thread.h"
#include "args.h"

void network(t_thread_data *thread_data);

void get_informations_from_server(int sock, t_thread_data *thread_data);

void ask_server(t_thread_data *thread_data, char *msg);

#endif		/* !NETWORK_H_ */

