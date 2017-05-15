/*
** quit.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Mon May 15 18:23:18 2017 arnaud.alies
** Last update Mon May 15 18:34:33 2017 arnaud.alies
*/

#include "server.h"

int     cmd_quit(t_ftp *ftp, char *cmd)
{
  (void)cmd;
  ftp_send(ftp, FTP_CLOSING, "Goodbye.");
  ftp->running = false;
  return (0);
}
