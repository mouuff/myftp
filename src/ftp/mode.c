/*
** mode.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed May 17 23:27:42 2017 arnaud.alies
** Last update Wed May 17 23:33:35 2017 arnaud.alies
*/

#include "server.h"

int	ftp_mode_fd(t_ftp *ftp)
{
  if (ftp->mode == M_PORT)
    return (-1);
  if (ftp->mode == M_PASV)
    return (ftp_passive_fd());
  return (-1);
}
