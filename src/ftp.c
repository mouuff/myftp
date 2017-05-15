/*
** ftp.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Sun May 14 15:36:59 2017 arnaud.alies
** Last update Mon May 15 17:45:14 2017 arnaud.alies
*/

#include <stdio.h>
#include <string.h>
#include "server.h"

int	ftp_send(t_ftp *ftp, int code, char *str)
{
  char	buff[BUFF_SIZE];

  if (code <= 0 || code > 999)
    snprintf(buff, BUFF_SIZE, "%s", str);
  else
    snprintf(buff, BUFF_SIZE, "%3d %s", code, str);
  return (server_send(ftp->client->fd, buff));
}

static int	ftp_init(t_ftp *ftp, t_server *server, t_client *client)
{
  ftp->server = server;
  ftp->client = client;
  ftp->logged = false;
  ftp->running = true;
  return (ftp_send(ftp, 220, "(myFTP)"));
}

static int	ftp_server(t_server *server, t_client *client)
{
  char		buff[BUFF_SIZE + 1];
  t_ftp		ftp;

  if (ftp_init(&ftp, server, client))
    return (1);
  while (ftp.running)
    {
      memset(buff, '\0', BUFF_SIZE + 1);
      if (read(client->fd, buff, BUFF_SIZE) < 1)
        return (1);
      if (strlen(buff) > 0 && buff[strlen(buff) - 1] == '\n')
	buff[strlen(buff) - 1] = '\0';
      if (cmd_run(&ftp, buff))
        return (1);
    }
  return (0);
}

int             ftp_accept(t_server *server)
{
  t_client      client;
  pid_t         pid;

  if (server_accept(&client, server))
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      ftp_server(server, &client);
      printf("Closing connection\n");
      exit(0);
    }
  else
    {
      printf("New client: %s\n", inet_ntoa(client.addr.sin_addr));
    }
  return (0);
}
