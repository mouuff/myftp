/*
** mode.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed May 17 23:27:42 2017 arnaud.alies
** Last update Thu May 18 13:25:25 2017 arnaud.alies
*/

#include "server.h"

int	ftp_mode_fd(t_ftp *ftp)
{
  if (ftp->mode == M_PORT)
    return (ftp_port_fd());
  if (ftp->mode == M_PASV)
    return (ftp_passive_fd());
  return (-1);
}
