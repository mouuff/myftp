/*
** get_next_crlf.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 19 16:39:49 2017 arnaud.alies
** Last update Fri May 19 16:39:50 2017 arnaud.alies
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
