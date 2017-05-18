/*
** port.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Thu May 18 10:35:26 2017 arnaud.alies
** Last update Thu May 18 11:35:22 2017 arnaud.alies
*/

#include "server.h"

int	ftp_port_fd()
{
  return (-1);
}

static int	get_ip_port(char *str, int *port, uint32_t *ip)
{
  t_args	*args;

  *port = 0;
  *ip = 0;
  args = my_str_args(str, ",");
  if (args->ac != 6)
    {
      my_free_str_args(args);
      return (1);
    }
  *port = (IARG(args, 4) << 8) + IARG(args, 5);
  *ip = IARG(args, 0);
  *ip += IARG(args, 1) << 8;
  *ip += IARG(args, 2) << 16;
  *ip += IARG(args, 3) << 24;
  my_free_str_args(args);
  return (0);
}

int		ftp_port(t_ftp *ftp, char *str)
{
  int		port;
  uint32_t	ip;
  char		buff[BUFF_SIZE];

  if (get_ip_port(str, &port, &ip))
    return (ftp_send(ftp, FTP_FAIL, "fail"));
  sprintf(buff, "%d.%d.%d.%d : %d",
	  GETBYTE(ip, 0), GETBYTE(ip, 1),
	  GETBYTE(ip, 2), GETBYTE(ip, 3), port);
  return (ftp_send(ftp, FTP_NOCODE, buff));
  return (0);
}
