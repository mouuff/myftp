/*
** pasv.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed May 17 11:11:14 2017 arnaud.alies
** Last update Thu May 18 13:38:35 2017 arnaud.alies
*/

#include <string.h>
#include <stdio.h>
#include "server.h"

int     		cmd_pasv(t_ftp *ftp, t_args *args)
{
  char			buff[BUFF_SIZE];
  struct sockaddr_in	addr;
  socklen_t		len;
  int			port;

  (void)args;
  ftp_port(NULL);
  if (ftp_passive(&port))
    {
      return (ftp_send(ftp, FTP_FAIL, "Could not create server."));
    }
  len = sizeof(addr);
  if (getsockname(ftp->client->fd, (struct sockaddr*)&(addr), &len) < 0)
    {
      return (ftp_send(ftp, FTP_FAIL, "Could not get server ip."));
    }
  ftp->mode = M_PASV;
  snprintf(buff, BUFF_SIZE, "Entering Passive Mode (%d,%d,%d,%d,%d,%d).",
	  GETBYTE(addr.sin_addr.s_addr, 0), GETBYTE(addr.sin_addr.s_addr, 1),
	  GETBYTE(addr.sin_addr.s_addr, 2), GETBYTE(addr.sin_addr.s_addr, 3),
	  GETBYTE(port, 1), GETBYTE(port, 0));
  return (ftp_send(ftp, FTP_PASV, buff));
}
