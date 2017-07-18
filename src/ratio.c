#include <resolution.h>
#include <error.h>
#include <stdlib.h>

/*
** ratio.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Tue Jul 18 10:18:26 2017 Loïc Pirez
** Last update Tue Jul 18 10:18:26 2017 Loïc Pirez
*/

int gcd(int a, int b)
{
    if (b == 0)
    {
        return (a);
    }
    return (gcd(b, a % b));
}

t_resolution *calc_aspect_ratio(int width, int height)
{
    t_resolution *ratio;

    if ((ratio = malloc(sizeof(t_resolution *))) == NULL)
    {
        print_error_and_exit(ERROR_MALLOC, 84);
    }
    float g = gcd(width, height);
    float x = (float) width / g;
    float y = (float) height / g;
    ratio->x = (int) x;
    ratio->y = (int) y;
    return (ratio);
}

t_resolution *calc_resolution_from_ratio(t_resolution *current_resolution, t_resolution *aspect_ratio)
{
    t_resolution *target;

    if ((target = malloc(sizeof(t_resolution *))) == NULL)
    {
        print_error_and_exit(ERROR_MALLOC, 84);
    }
    target->x = aspect_ratio->x * (aspect_ratio->x * 100 < current_resolution->x ? 200 : 20);
    target->y = aspect_ratio->y * (aspect_ratio->y * 100 < current_resolution->y ? 200 : 20);
    return (target);
}
