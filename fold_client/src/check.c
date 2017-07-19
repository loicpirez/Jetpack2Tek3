/*
** check_map.c for client in /home/loicpirez/Développement/CLionProjects/jetpack2Tek3_2016
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Sat Jul 15 17:37:19 2017 Loïc Pirez
** Last update Tue Jul 18 21:08:36 2017 Loïc Pirez
*/

#include <printf.h>
#include <string.h>
#include <error.h>
#include <stdlib.h>
#include <network.h>
#include <strings.h>
#include <stdio.h>
#include <array.h>
#include <get.h>
#include <check.h>

void check_map(char **answer, t_thread_data *thread_data)
{
  int index = find_index(answer, "MAP");
  if (!answer[index + 1] || !answer[index + 2] || !answer[index + 3] ||
      (sscanf(answer[index + 1], "%zu", &thread_data->server_data->mapX) != 1) ||
      (sscanf(answer[index + 2], "%zu", &thread_data->server_data->mapY) != 1))
    {
      print_error_and_exit(ERROR_MAPFORMAT, 84);
    }
  thread_data->server_data->raw_map = answer[index + 3];
  if (strlen(thread_data->server_data->raw_map) != thread_data->server_data->mapX * thread_data->server_data->mapY)
    {
      print_error_and_exit(ERROR_MAPFORMAT, 84);
    }
  thread_data->server_data->raw_map[thread_data->server_data->mapX * thread_data->server_data->mapY + 1] = 0;
  if ((check_string_content(thread_data->server_data->raw_map, "_ec")) == false)
    {
      print_error_and_exit(ERROR_MAPFORMAT, 84);
    }
}

void check_id(char **answer, t_thread_data *thread_data)
{
  int index = find_index(answer, "ID");
  if (!answer[index + 1] || (sscanf(answer[index + 1], "%d", &thread_data->server_data->id) != 1))
    {
      print_error_and_exit(ERROR_IDFORMAT, 84);
    }
  thread_data->server_data->id = atoi(answer[index + 1]);
}

void get_pos(t_thread_data *thread_data, int x, int y)
{
  char *copy;
  int i = 0;
  int search_x = 0;
  int search_y = 0;

  if ((copy = malloc(sizeof(char) + strlen(thread_data->server_data->raw_map) + 1)) == NULL)
    print_error_and_exit(ERROR_MALLOC, 84);
  strcpy(copy, thread_data->server_data->raw_map);
  reverse_string(copy);
  while (copy[i])
    {
      if (search_x == (int)thread_data->server_data->mapX - x && search_y == y)
        {
	  copy[i] = '_';
        }
      if (search_x == (int)thread_data->server_data->mapX - 1)
        {
	  search_x = 0;
	  search_y++;
        }
      else
        {
	  search_x += 1;
        }
      i++;
      fflush(0);
    }
  reverse_string(copy);
  thread_data->server_data->raw_map = copy;
}

void check_coin(char **answer, t_thread_data *thread_data)
{
  int index = find_index(answer, "COIN");
  int nb_player = 0;
  int x = 0;
  int y = 0;

  if (!answer[index + 1] || (sscanf(answer[index + 1], "%d", &nb_player) != 1) || !answer[index + 2] ||
      (sscanf(answer[index + 2], "%d", &x) != 1) || !answer[index + 3] || (sscanf(answer[index + 3], "%d", &y) != 1))
    {
      print_error_and_exit(ERROR_COINFORMAT, 84);
    }
  else
    {
      get_pos(thread_data, x, y);
    }
}

void check_player(char **answer, int array_length, t_thread_data *thread_data)
{
  if (array_length < MAX_WORDS - 2)
    {
      print_error_and_exit(ERROR_PLAYERFORMAT, 84);
    }
  if ((count_occurencies(answer, "PLAYER")) != 2)
    {
      print_error_and_exit(ERROR_PLAYERFORMAT, 84);
    }
  get_player_informations(answer, "1", thread_data);
  get_player_informations(answer, "2", thread_data);
}

void check_end(char **answer, t_thread_data *thread_data)
{
  int index = find_index(answer, "FINISH");
  char *value = answer[index + 1];

  if (value)
    {
      if (atoi(value) != -1 || atoi(value) != 1 || atoi(value) != 2)
        {
	  thread_data->server_data->winner = atoi(value);
	  thread_data->server_data->is_finish = true;
        }
      else
        {
	  print_error_and_exit(ERROR_ENDFORMAT, 84);
        }
    }
  else
    {
      print_error_and_exit(ERROR_ENDFORMAT, 84);
    }
}

void check_answer(char **answer, t_thread_data *thread_data)
{
  int array_length = get_array_length(answer);

  if (find_index(answer, "ID") != INDEX_NOT_FOUND)
    check_id(answer, thread_data);
  if (find_index(answer, "START") != INDEX_NOT_FOUND)
    thread_data->server_data->is_ready = true;
  if (find_index(answer, "MAP") != INDEX_NOT_FOUND)
    check_map(answer, thread_data);
  if (find_index(answer, "COIN") != INDEX_NOT_FOUND)
    check_coin(answer, thread_data);
  if (find_index(answer, "PLAYER") != INDEX_NOT_FOUND)
    check_player(answer, array_length, thread_data);
  if (find_index(answer, "FINISH") != INDEX_NOT_FOUND)
    check_end(answer, thread_data);
}
