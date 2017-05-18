/*
** list.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed May 17 23:30:47 2017 arnaud.alies
** Last update Thu May 18 13:47:20 2017 arnaud.alies
*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include "server.h"

static int	send_listing(int fd, char *dir)
{
  DIR		*dp;
  struct dirent	*ep;

  if (dir == NULL)
    dp = opendir("./");
  else
    dp = opendir(dir);
  if (dp == NULL)
    return (1);
  while ((ep = readdir(dp)))
    {
      if (sock_send(fd, ep->d_name))
	{
	  closedir(dp);
	  return (0);
	}
    }
  closedir (dp);
  return (0);
}

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
      if (ftp_send(ftp, FTP_FILEOK, "Here comes the directory listing."))
	return (1);
      if (args->ac > 1)
	send_listing(fd, (args->av)[1]);
      else
	send_listing(fd, NULL);
      clean_close_fd(fd);
      return (ftp_send(ftp, FTP_CLOSING_DATA, "Closing data connection."));
    }
  return (0);
}
