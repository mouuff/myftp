/*
** ftp.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Sun May 14 15:36:59 2017 arnaud.alies
** Last update Wed May 17 11:35:27 2017 arnaud.alies
*/

#include <stdio.h>
#include <string.h>
#include "server.h"

static int	ftp_init(t_ftp *ftp, t_sock *server, t_client *client)
{
  ftp->server = server;
  ftp->client = client;
  ftp->logged = false;
  ftp->anonymous = false;
  ftp->running = true;
  return (ftp_send(ftp, FTP_RDY, "(myFTP)"));
}

static int	ftp_server(t_sock *server, t_client *client, char *home)
{
  char		buff[BUFF_SIZE + 1];
  t_ftp		ftp;

  chdir(home);
  if (ftp_init(&ftp, server, client))
    return (1);
  while (ftp.running)
    {
      if (ftp_read(&ftp, buff, BUFF_SIZE))
	return (1);
      if (cmd_run(&ftp, buff))
        return (1);
    }
  return (0);
}

int             ftp_accept(t_sock *server, char *home)
{
  t_client      client;
  pid_t         pid;

  if (server_accept(&client, server))
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      ftp_server(server, &client, home);
      printf("Closing connection\n");
      exit(0);
    }
  else
    {
      clean_close_fd(client.fd);
      printf("New client: %s\n", inet_ntoa(client.addr.sin_addr));
    }
  return (0);
}
