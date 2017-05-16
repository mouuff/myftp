/*
** user.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Mon May 15 18:43:48 2017 arnaud.alies
** Last update Tue May 16 13:21:20 2017 arnaud.alies
*/

#include <string.h>
#include "server.h"

static void	replace_space(char *str)
{
  int		x;

  x = 0;
  while (str[x] != '\0')
    {
      if (str[x] == ' ')
	{
	  str[x] = '\0';
	  return ;
	}
      x += 1;
    }
}

static int	try_log(t_ftp *ftp, t_args *args, char *buff)
{
  if (ftp_send(ftp, FTP_NEED_PASS, "Please specify the password."))
    return (1);
  ftp_read(ftp, buff, BUFF_SIZE);
  replace_space(buff);
  if (strcasecmp(buff, "pass") == 0)
    {
      if (args->ac != 2 || strcasecmp((args->av)[1], "anonymous") != 0)
	{
	  return (ftp_send(ftp, FTP_NOT_LOGGED, "Login incorrect."));
	}
      else
	{
	  ftp->logged = true;
	  return (ftp_send(ftp, FTP_LOGGED, "Login successful."));
	}
    }
  else
    return (ftp_send(ftp, FTP_NOT_LOGGED, "Please login with USER and PASS."));
  return (0);
}

int	cmd_user(t_ftp *ftp, t_args *args)
{
  char	buff[BUFF_SIZE + 1];

  if (ftp->logged)
    return (ftp_send(ftp, FTP_NOT_LOGGED, "Can't change from guest user."));
  else
    {
      if (args->ac < 2)
	return (ftp_send(ftp, FTP_NOT_LOGGED, "Permission denied."));
      else
	{
	  if (try_log(ftp, args, buff))
	    return (1);
	}
    }
  return (0);
}
