/*
** pwd.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue May 16 13:28:39 2017 arnaud.alies
** Last update Tue May 16 13:44:28 2017 arnaud.alies
*/

#include "server.h"

int     cmd_pass(t_ftp *ftp, t_args *args)
{
  (void)args;
  if (ftp->logged)
    return (ftp_send(ftp, FTP_LOGGED, "Already logged in."));
  if (ftp->anonymous)
    {
      ftp->logged = true;
      return (ftp_send(ftp, FTP_LOGGED, "Login successful."));
    }
  else
    {
      return (ftp_send(ftp, FTP_NOT_LOGGED, "Login incorrect."));
    }
  return (0);
}
