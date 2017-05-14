/*
** ftp.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Sun May 14 15:36:59 2017 arnaud.alies
** Last update Sun May 14 16:02:34 2017 arnaud.alies
*/

#include <stdio.h>
#include <string.h>
#include "server.h"

static void	ftp_init(t_ftp *ftp, t_server *server, t_client *client)
{
  ftp->server = server;
  ftp->client = client;
  ftp->logged = false;
  ftp->running = true;
  server_send(ftp->client->fd, "220");
}

static int	ftp_server(t_server *server, t_client *client)
{
  char		buff[BUFF_SIZE + 1];
  t_ftp		ftp;
  int		rd;

  ftp_init(&ftp, server, client);
  while (ftp.running)
    {
      memset(buff, '\0', BUFF_SIZE + 1);
      if ((rd = read(client->fd, buff, BUFF_SIZE)) == -1)
        return (1);
      printf("%d : %s\n", rd, buff);
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
      exit(0);
    }
  else
    {
      printf("New client: %s\n", inet_ntoa(client.addr.sin_addr));
    }
  return (0);
}
