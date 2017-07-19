/*
** args.h for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Fri Jul 14 13:19:03 2017 Loïc Pirez
** Last update Tue Jul 18 21:17:43 2017 Loïc Pirez
*/

#ifndef		RATIO_H_
# define	RATIO_H_

#include "resolution.h"

int gcd(int a, int b);

t_resolution *calc_aspect_ratio(int width, int height);

t_resolution *calc_resolution_from_ratio(t_resolution *current_resolution, t_resolution *aspect_ratio);

#endif		/* !RATIO_H_ */

