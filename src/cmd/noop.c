/*
** noop.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue May 16 16:09:15 2017 arnaud.alies
** Last update Tue May 16 16:15:43 2017 arnaud.alies
*/

#include "server.h"

int	cmd_noop(t_ftp *ftp, t_args *args)
{
  (void)args;
  return (ftp_send(ftp, FTP_OK, "NOOP ok."));
}
