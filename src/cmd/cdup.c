/*
** cdup.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue May 16 15:35:44 2017 arnaud.alies
** Last update Tue May 16 15:49:17 2017 arnaud.alies
*/

#include <unistd.h>
#include "server.h"

int     cmd_cdup(t_ftp *ftp, t_args *args)
{
  (void)args;
  if (chdir("..") == -1)
    return (ftp_send(ftp, FTP_FAIL, "Failed to change directory."));
  return (ftp_send(ftp, FTP_COMPLETED, "Directory successfully changed."));
}
