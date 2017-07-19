/*
** open_file.c for server in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016/server/src/Map_Handling/open_file.c
**
** Made by Valerian VERMEULEN
** Login   <valerian.vermeulen@epitech.eu>
**
** Started on  Sun Jul 16 21:12:23 2017 Valerian VERMEULEN
** Last update Sun Jul 16 21:12:23 2017 Valerian VERMEULEN
*/

#include	"Map_Func/open_file.h"

FILE		*open_file(char *filename)
{
  FILE		*fd;

  fd = fopen(filename, "r");
  if (fd == NULL)
    exit(84);
  return (fd);
}