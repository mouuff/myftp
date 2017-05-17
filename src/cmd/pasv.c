/*
** pasv.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed May 17 11:11:14 2017 arnaud.alies
** Last update Wed May 17 18:38:11 2017 arnaud.alies
*/

#include <string.h>
#include <stdio.h>
#include "server.h"

int     		cmd_pasv(t_ftp *ftp, t_args *args)
{
  char			buff[500];
  char			ip[20];
  struct sockaddr_in	addr;
  socklen_t		len;
  int			port;

  if (ftp_passive(&port))
    {
      ftp_send(ftp, FTP_FAIL, "Could not create server.");
      return (0);
    }
  len = sizeof(addr);
  if (getsockname(ftp->client->fd, (struct sockaddr*)&(addr), &len) < 0)
    {
      ftp_send(ftp, FTP_FAIL, "Could not get server ip.");
      return (0);
    }
  strcpy(ip, inet_ntoa(addr.sin_addr));
  sprintf(buff, "PORT: %s %d", ip, port);
  ftp_send(ftp, FTP_NOCODE, buff);
  return (0);
}
