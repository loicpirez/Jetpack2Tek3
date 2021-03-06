/*
** error.h for error in /home/loicpirez/CLionProjects/untitled/include
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:23:35 2017 Loïc Pirez
** Last update Tue Jul 18 21:17:31 2017 Loïc Pirez
*/

#ifndef		ERROR_H_
# define	ERROR_H_

enum e_error
{
    ERROR_MALLOC,
    ERROR_SDL,
    ERROR_COMMAND,
    ERROR_THREAD,
    ERROR_PORTFORMAT,
    ERROR_IPFORMAT,
    ERROR_RESFORMAT,
    ERROR_MISSINGARGS,
    ERROR_SOCKET,
    ERROR_CONNECT,
    ERROR_SEND,
    ERROR_RECV,
    ERROR_MAPFORMAT,
    ERROR_FD,
    ERROR_BIGPACKET,
    ERROR_IDFORMAT,
    ERROR_PLAYERFORMAT,
    ERROR_ENDFORMAT,
    ERROR_COINFORMAT
};

void print_error_and_exit(int id, int status);

void print_err(char *msg);

#endif		/* !ERROR_H_ */

