/*
** send.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue May 16 14:36:36 2017 arnaud.alies
** Last update Wed May 17 10:15:46 2017 arnaud.alies
*/

#include <stdio.h>
#include <string.h>
#include "server.h"

int     ftp_send(t_ftp *ftp, t_code code, char *str)
{
  char  buff[BUFF_SIZE];

  if (code == FTP_NOCODE)
    snprintf(buff, BUFF_SIZE, "%s", str);
  else
    snprintf(buff, BUFF_SIZE, "%3d %s", code, str);
  return (server_send(ftp->client->fd, buff));
}
