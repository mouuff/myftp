/*
** stor.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Thu May 18 18:52:10 2017 arnaud.alies
** Last update Thu May 18 19:58:42 2017 arnaud.alies
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "server.h"

static void     send_file(int sockfd, int filefd)
{
  char          buff[BUFF_SIZE + 1];
  int           r;

  memset(buff, 0, BUFF_SIZE + 1);
  while ((r = read(sockfd, buff, BUFF_SIZE)) > 0)
    {
      write(filefd, buff, r);
    }
  clean_close_fd(sockfd);
  close(filefd);
}

int	cmd_stor(t_ftp *ftp, t_args *args)
{
  int   filefd;
  int   sockfd;

  sockfd = ftp_mode_fd(ftp);
  if (sockfd < 0)
    {
      if (ftp->mode == M_NO)
        return (ftp_send(ftp, FTP_CANT_DATA, "Use PORT or PASV first."));
      return (ftp_send(ftp, FTP_CANT_DATA, "Can't open data connection."));
    }
  else
    {
      if ((filefd = open(args->av[1], O_CREAT | O_WRONLY, 0644)) == -1)
        return (ftp_send(ftp, FTP_FAIL, "Failed to create file."));
      ftp_send(ftp, FTP_FILEOK, "Sending file.");
      send_file(sockfd, filefd);
      return (ftp_send(ftp, FTP_CLOSING_DATA, "Closing data connection."));
    }
  return (0);
}
