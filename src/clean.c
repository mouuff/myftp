/*
** cleaner.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Sat May 13 11:11:48 2017 arnaud.alies
** Last update Mon May 15 18:14:12 2017 arnaud.alies
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

static int *g_fds = NULL;
static int g_size = 0;

void	clean_add_fd(int fd)
{
  int	*res;

  res = xmalloc(sizeof(int) * (g_size + 1));
  res[g_size] = fd;
  if (g_fds != NULL)
    memcpy(res, g_fds, sizeof(int) * g_size);
  g_size += 1;
  free(g_fds);
  g_fds = res;
}

void		clean_close_fd(int fd)
{
  int		*res;
  register int	x;
  register int	y;

  res =	xmalloc(sizeof(int) * g_size);
  x = 0;
  y = 0;
  while (x < g_size)
    {
      if (fd != g_fds[x])
	{
	  res[y] = g_fds[x];
	  y += 1;
	}
      x += 1;
    }
  if (x != y)
    g_size -= 1;
  free(g_fds);
  g_fds = res;
  close(fd);
}

void		clean()
{
  if (errno != 0)
    printf("Error: %s\n", strerror(errno));
  while (g_size > 0)
    {
      clean_close_fd(g_fds[g_size - 1]);
    }
  free(g_fds);
  g_fds = NULL;
}
