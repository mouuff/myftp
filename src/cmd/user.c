/*
** user.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Mon May 15 18:43:48 2017 arnaud.alies
** Last update Tue May 16 13:44:18 2017 arnaud.alies
*/

#include <string.h>
#include "server.h"

int	cmd_user(t_ftp *ftp, t_args *args)
{
  if (ftp->logged)
    return (ftp_send(ftp, FTP_NOT_LOGGED, "Can't change from guest user."));
  if (args->ac < 2)
    return (ftp_send(ftp, FTP_NOT_LOGGED, "Permission denied."));
  ftp->anonymous = (strcasecmp((args->av)[1], "anonymous") == 0);
  if (ftp_send(ftp, FTP_NEED_PASS, "Please specify the password."))
    return (1);
  return (0);
}
