/*
** read.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue May 16 14:37:30 2017 arnaud.alies
** Last update Tue May 16 18:58:33 2017 arnaud.alies
*/

#include <stdio.h>
#include <string.h>
#include "server.h"

int     ftp_read(t_ftp *ftp, char *buff, size_t size)
{
  char	*r;

  if ((r = get_next_crlf(ftp->client->fd)) == NULL)
    return (1);
  strncpy(buff, r, size);
  free(r);
  return (0);
}
