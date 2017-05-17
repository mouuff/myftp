/*
** cwd.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed May 17 10:43:37 2017 arnaud.alies
** Last update Wed May 17 10:46:52 2017 arnaud.alies
*/

#include "server.h"

int	cmd_cwd(t_ftp *ftp, t_args *args)
{
  if (args->ac > 1 && chdir((args->av)[1]) != -1)
    return (ftp_send(ftp, FTP_COMPLETED, "Directory successfully changed."));
  return (ftp_send(ftp, FTP_FAIL, "Failed to change directory."));
}
