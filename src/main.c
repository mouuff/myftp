/*
** main.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:36 2017 arnaud.alies
** Last update Sun May 14 14:15:27 2017 arnaud.alies
*/

#include <stdio.h>
#include <signal.h>
#include "server.h"

void	sigint(int sig)
{
  (void)sig;
  printf("\n");
  exit(0);
}

void	ftp_init(t_ftp *ftp, t_server *server, t_client *client)
{
  ftp->server = server;
  ftp->client = client;
  ftp->logged = false;
  ftp->running = true;
  server_send(ftp->client->fd, "220");
}

void	ftp_server(t_server *server, t_client *client)
{
  
  t_ftp	ftp;

  ftp_init(&ftp, server, client);
  while (ftp.running)
    {
      
    }
}

int		ftp_accept(t_server *server)
{
  t_client	client;
  pid_t		pid;

  if (server_accept(&client, server) == 1)
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

int		main()
{
  t_server	server;
  int		port;

  port = 4242;
  signal(SIGINT, &sigint);
  atexit(clean);  
  if ((server_init(&server, port)) == 1)
    return (1);
  printf("Server listenning on: %d\n", port);
  while (42)
    {
      if (ftp_accept(&server) == 1)
	return (1);
    }
  return (0);
}
