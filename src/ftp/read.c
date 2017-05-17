/*
** read.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue May 16 14:37:30 2017 arnaud.alies
** Last update Wed May 17 10:12:53 2017 arnaud.alies
*/

#include <stdio.h>
#include <string.h>
#include "server.h"

int     ftp_read(t_ftp *ftp, char *buff, size_t size)
{
  char	*r;
  int	len;

  if ((r = get_next_crlf(ftp->client->fd)) == NULL)
    return (1);
  len = strlen(r);
  if (len > 0 && r[len - 1] == '\r')
    r[len - 1] = '\0';
  memset(buff, 0, size);
  strncpy(buff, r, size - 1);
  free(r);
  return (0);
}
