/*
** command.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Sun May 14 15:47:12 2017 arnaud.alies
** Last update Tue May 16 09:14:41 2017 arnaud.alies
*/

#include <string.h>
#include "server.h"

static t_cmd g_unlogged_cmds[] = {
  DEF_CMD(quit),
  DEF_CMD(user),
  {NULL, NULL}
};

static t_cmd g_logged_cmds[] = {
  {NULL, NULL}
};

static int	cmd_run_cmds(t_ftp *ftp, char *cmd, t_cmd *cmds, bool *run)
{
  int		len;
  int		x;

  len = strlen(cmd);
  if (len <= 0)
    return (0);
  x = 0;
  while (cmds[x].str != NULL)
    {
      if (strncasecmp(cmds[x].str, cmd, len) == 0)
	{
	  *run = true;
	  return (cmds[x].func(ftp, cmd));
	}
      x += 1;
    }
  return (0);
}

int	cmd_run(t_ftp *ftp, char *str)
{
  bool	run;

  run = false;
  if (cmd_run_cmds(ftp, str, g_unlogged_cmds, &run))
    return (1);
  if (ftp->logged && run == false)
    {
      if (cmd_run_cmds(ftp, str, g_logged_cmds, &run))
	return (1);
    }
  if (run == false)
    {
      //unknown cmd
    }
  return (0);
}
