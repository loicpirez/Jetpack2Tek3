/*
** check.h for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Sat Jul 15 17:38:13 2017 Loïc Pirez
** Last update Sat Jul 15 17:38:13 2017 Loïc Pirez
*/

#ifndef        CHECK_H_
# define    CHECK_H_

#include "thread.h"

void check_player(char **answer, int array_length, t_thread_data *thread_data);

void check_id(char **answer, t_thread_data *thread_data);

void check_answer(char **answer, t_thread_data *thread_data);

void check_map(char *reply, t_thread_data *thread_data);

#endif        /* !CHECK_H_ */
