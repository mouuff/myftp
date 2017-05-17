/*
** help.c for heu in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue May 16 16:23:39 2017 arnaud.alies
** Last update Wed May 17 10:35:27 2017 arnaud.alies
*/

#include "server.h"

int	cmd_help(t_ftp *ftp, t_args *args)
{
  (void)args;
  ftp_send(ftp, FTP_HELP, "The following commands are recognized.");
  ftp_send(ftp, FTP_NOCODE, " USER PASS QUIT PWD CDUP NOOP HELP");
  ftp_send(ftp, FTP_HELP, "Help OK.");
  return (0);
}
