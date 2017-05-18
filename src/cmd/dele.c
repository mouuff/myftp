/*
** dele.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Thu May 18 14:04:59 2017 arnaud.alies
** Last update Thu May 18 14:49:43 2017 arnaud.alies
*/

#include <stdio.h>
#include "server.h"

int	cmd_dele(t_ftp *ftp, t_args *args)
{
  if (args->ac <= 1)
    return (ftp_send(ftp, FTP_FAIL, "Permission denied."));
  if (remove(args->av[1]) < 0)
    return (ftp_send(ftp, FTP_FAIL, "Permission denied."));
  return (ftp_send(ftp, FTP_COMPLETED, "Deleted file."));
}
