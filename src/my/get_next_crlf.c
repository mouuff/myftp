/*
** get_next_line.c for get_next_line in /home/alies/rendu/CPE_2015_getnextline
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Dec 17 13:44:58 2015 Arnaud Alies
** Last update Wed May 17 10:11:21 2017 arnaud.alies
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	*get_next_crlf(int fd)
{
  char	*buff;
  char	c;
  int	size;
  int	rd_size;

  size = 0;
  buff = NULL;
  while (42)
    {
      rd_size = read(fd, &c, 1);
      if (rd_size <= 0)
	{
	  free(buff);
	  return (NULL);
	}
      buff = my_realloc(buff, sizeof(char) * (size + 2));
      buff[size] = c;
      buff[size + 1] = '\0';
      size += 1;
      if (size > 0 && buff[size - 1] == '\n')
	{
	  buff[size - 1] = '\0';
	  return (buff);
	}
    }
}
