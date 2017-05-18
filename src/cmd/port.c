/*
** port.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed May 17 11:12:44 2017 arnaud.alies
** Last update Thu May 18 11:39:45 2017 arnaud.alies
*/

#include "server.h"

int     cmd_port(t_ftp *ftp, t_args *args)
{
  (void)ftp;
  (void)args;
  if (args->ac < 2)
    return (ftp_send(ftp, FTP_SYNTAX, "Illegal PORT command."));
  if (ftp_port(ftp, args->av[1]))
    return (ftp_send(ftp, FTP_SYNTAX, "Illegal PORT command."));
  return (0);
}
