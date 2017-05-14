/*
** command.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Sun May 14 15:47:12 2017 arnaud.alies
** Last update Sun May 14 18:09:33 2017 arnaud.alies
*/

#include <string.h>
#include "server.h"

int	cmd_quit(t_ftp *ftp, char *cmd)
{
  (void)cmd;
  server_send(ftp->client->fd, "221 Goodbye.");
  ftp->running = false;
  return (0);
}

t_cmd cmds[] = {
  {"quit", &cmd_quit},
  {NULL, NULL}
};


int	cmd_run(t_ftp *ftp, char *cmd)
{
  int	len;
  int	x;

  len = strlen(cmd);
  if (len <= 0)
    return (0);
  x = 0;
  while (cmds[x].str != NULL)
    {
      if (strncasecmp(cmds[x].str, cmd, len) == 0)
	{
	  return (cmds[x].func(ftp, cmd));
	}
      x += 1;
    }
  return (0);
}
