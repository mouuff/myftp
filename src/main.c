/*
** main.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:36 2017 arnaud.alies
** Last update Fri May 19 17:14:35 2017 arnaud.alies
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "server.h"

void	sigint(int sig)
{
  (void)sig;
  exit(0);
}

int		main(int ac, char **av)
{
  t_server	server;
  int		port;
  char		*home;

  if (ac != 3)
    {
      fprintf(stderr, "Usage : ./server port path\n");
      return (1);
    }
  port = atoi(av[1]);
  home = av[2];
  signal(SIGINT, &sigint);
  atexit(clean);
  if (server_init(&server, port, true))
    return (1);
  printf("Server listenning on: %d\n", port);
  while (42)
    {
      if (ftp_accept(&server, home))
	return (1);
    }
  return (0);
}
