/*
** main.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:36 2017 arnaud.alies
** Last update Tue May 16 16:33:30 2017 arnaud.alies
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

void	test()
{
  t_args *args;
  int	x;

  x = 0;
  args = my_str_args("s s  ssss     ");

  while (x < args->ac)
    {
      printf(">%s<\n", args->av[x]);
      x += 1;
    }
  my_free_str_args(args);
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
  if (server_init(&server, port))
    return (1);
  printf("Server listenning on: %d\n", port);
  while (42)
    {
      if (ftp_accept(&server, home))
	return (1);
    }
  return (0);
}
