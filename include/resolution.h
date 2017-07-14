/*
** resolution.h for resolution in /home/loicpirez/CLionProjects/untitled/include
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:23:35 2017 Loïc Pirez
** Last update Thu Jul 13 15:23:41 2017 Loïc Pirez
*/

#ifndef		RESOLUTION_H_
# define	RESOLUTION_H_

typedef struct s_resolution {
    int        x;
    int        y;
}              t_resolution;

enum           e_format {
    CORRECT_FORMAT,
    WRONG_FORMAT
};

t_resolution	*get_current_resolution(void);

#endif		/* !RESOLUTION_H_ */
