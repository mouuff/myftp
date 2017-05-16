/*
** read.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue May 16 14:37:30 2017 arnaud.alies
** Last update Tue May 16 18:50:55 2017 arnaud.alies
*/

#include <stdio.h>
#include <string.h>
#include "server.h"

int     ftp_read(t_ftp *ftp, char *buff, size_t size)
{
  char	*r;

  if ((r = get_next_crlf(ftp->client->fd)) == NULL)
    return (1);
  memset(buff, 0, size);
  strncpy(buff, r, size - 1);
  /*
  int   len;

  if (read(ftp->client->fd, buff, size - 1) < 1)
    return (1);
  len = strlen(buff);
  if (len > 0 && buff[len - 1] == '\n')
    buff[len - 1] = '\0';
  len = strlen(buff);
  if (len > 0 && buff[len - 1] == '\r')
    buff[len - 1] = '\0';
  */
  return (0);
}
