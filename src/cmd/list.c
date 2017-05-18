/*
** list.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed May 17 23:30:47 2017 arnaud.alies
** Last update Thu May 18 10:17:59 2017 arnaud.alies
*/

#include "server.h"

int	cmd_list(t_ftp *ftp, t_args *args)
{
  int	fd;

  fd = ftp_mode_fd(ftp);
  if (fd < 0)
    {
      if (ftp->mode == M_NO)
	return (ftp_send(ftp, FTP_CANT_DATA, "Use PORT or PASV first."));
      return (ftp_send(ftp, FTP_CANT_DATA, "Can't open data connection."));
    }
  else
    {
      write(fd, "hue\r\n", 5);
      return (ftp_send(ftp, FTP_CLOSING_DATA, "Closing data connection."));
    }
  return (0);
}
