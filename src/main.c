/*
** main.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:36 2017 arnaud.alies
** Last update Sun May 14 12:22:40 2017 arnaud.alies
*/

#include <stdio.h>
#include <signal.h>
#include "server.h"

void	sigint(int sig)
{
  (void)sig;
  exit(0);
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

  port = 4241;
  signal(SIGINT, &sigint);
  atexit(clean);  
  if ((server_init(&server, port)) == -1)
    return (1);
  printf("Server listenning on: %d\n", port);
  while (42)
    {
      if (ftp_accept(&server) == 1)
	return (1);
    }
  return (0);
}
