/*
** command.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Sun May 14 15:47:12 2017 arnaud.alies
** Last update Tue May 16 15:39:33 2017 arnaud.alies
*/

#include <string.h>
#include "server.h"

static t_cmd g_cmds[] = {
  DEF_CMD(quit),
  DEF_CMD(user),
  DEF_CMD(pass),
  {NULL, NULL}
};

static t_cmd g_logged_cmds[] = {
  DEF_CMD(pwd),
  DEF_CMD(cdup),
  {NULL, NULL}
};

static int	cmd_default(t_ftp *ftp, t_args *args)
{
  if (args->ac <= 0)
    return (0);
  if (ftp->logged)
    {
      if (ftp_send(ftp, FTP_SYNTAX, "Unknown command."))
	return (1);
    }
  else
    {
      if (ftp_send(ftp, FTP_NOT_LOGGED, "Please login with USER and PASS."))
	return (1);
    }
  return (0);
}

static int	cmd_run_cmds(t_ftp *ftp, t_args *args, t_cmd *cmds, bool *run)
{
  int		x;

  if (args->ac == 0)
    return (0);
  x = 0;
  while (cmds[x].str != NULL)
    {
      if (strcasecmp(cmds[x].str, (args->av)[0]) == 0)
	{
	  *run = true;
	  return (cmds[x].func(ftp, args));
	}
      x += 1;
    }
  return (0);
}

int		cmd_run(t_ftp *ftp, char *str)
{
  t_args	*args;
  bool		run;

  args = my_str_args(str);
  run = false;
  if (cmd_run_cmds(ftp, args, g_cmds, &run))
    {
      my_free_str_args(args);
      return (1);
    }
  if (ftp->logged && run == false)
    {
      if (cmd_run_cmds(ftp, args, g_logged_cmds, &run))
	{
	  my_free_str_args(args);
	  return (1);
	}
    }
  if (run == false && cmd_default(ftp, args))
    {
      my_free_str_args(args);
      return (1);
    }
  my_free_str_args(args);
  return (0);
}
