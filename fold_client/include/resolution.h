/*
** resolution.h for resolution in /home/loicpirez/CLionProjects/untitled/include
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:23:35 2017 Loïc Pirez
** Last update Tue Jul 18 21:17:45 2017 Loïc Pirez
*/

#ifndef		RESOLUTION_H_
# define	RESOLUTION_H_

typedef struct s_resolution
{
    int x;
    int y;
} t_resolution;

t_resolution *get_current_resolution(void);

#endif		/* !RESOLUTION_H_ */

