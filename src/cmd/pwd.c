/*
** pwd.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue May 16 13:28:39 2017 arnaud.alies
** Last update Tue May 16 15:34:27 2017 arnaud.alies
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

int     cmd_pwd(t_ftp *ftp, t_args *args)
{
  char	*res;
  char	*cwd;
  int	rep;

  (void)args;
  if ((cwd = getcwd(NULL, 0)) == NULL)
    return (1);
  res = my_malloc(sizeof(char) * (strlen(cwd) + 3));
  snprintf(res, strlen(cwd) + 3, "\"%s\"", cwd);
  rep = ftp_send(ftp, FTP_PWD, res);
  free(res);
  free(cwd);
  return (rep);
}
