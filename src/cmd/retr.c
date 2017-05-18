/*
** retr.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Thu May 18 16:25:36 2017 arnaud.alies
** Last update Thu May 18 18:42:30 2017 arnaud.alies
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "server.h"

void	send_file(int sockfd, int filefd)
{
  char	buff[BUFF_SIZE + 1];
  int	r;

  memset(buff, 0, BUFF_SIZE + 1);
  while ((r = read(filefd, buff, BUFF_SIZE)) > 0)
    {
      write(sockfd, buff, r);
    }
  clean_close_fd(sockfd);
  close(filefd);
}

int	cmd_retr(t_ftp *ftp, t_args *args)
{
  int	filefd;
  int	sockfd;

  sockfd = ftp_mode_fd(ftp);
  if (sockfd < 0)
    {
      if (ftp->mode == M_NO)
        return (ftp_send(ftp, FTP_CANT_DATA, "Use PORT or PASV first."));
      return (ftp_send(ftp, FTP_CANT_DATA, "Can't open data connection."));
    }
  else
    {
      if ((filefd = open((args->ac > 1 ? args->av[1] : "" ), O_RDONLY)) == -1)
	return (ftp_send(ftp, FTP_FAIL, "Failed to open file."));
      ftp_send(ftp, FTP_FILEOK, "Sending file.");
      send_file(sockfd, filefd);
      return (ftp_send(ftp, FTP_CLOSING_DATA, "Closing data connection."));
    }
  return (0);
}
