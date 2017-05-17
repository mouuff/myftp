/*
** pasv.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed May 17 11:11:14 2017 arnaud.alies
** Last update Wed May 17 17:13:21 2017 arnaud.alies
*/

#include "server.h"

int     cmd_pasv(t_ftp *ftp, t_args *args)
{
  char	buff[50];
  int	port;

  (void)ftp;
  (void)args;
  if (ftp_passive(&port))
    {
      ftp_send(ftp, FTP_NOCODE, "FAIL");
      return (0);
    }
  sprintf(buff, "PORT: %d", port);
  ftp_send(ftp, FTP_NOCODE, buff);
  return (0);
}
