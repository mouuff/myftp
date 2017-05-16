/*
** pwd.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue May 16 13:28:39 2017 arnaud.alies
** Last update Tue May 16 14:06:31 2017 arnaud.alies
*/

#include <unistd.h>
#include "server.h"

int     cmd_pwd(t_ftp *ftp, t_args *args)
{
  char	*cwd;
  int	rep;

  if ((cwd = getcwd(NULL, 0)) == NULL)
    return (1);
  rep = ftp_send(ftp, FTP_PWD, cwd);
  free(cwd);
  return (rep);
}
