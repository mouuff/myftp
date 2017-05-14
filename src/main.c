/*
** main.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:36 2017 arnaud.alies
** Last update Sun May 14 15:59:22 2017 arnaud.alies
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

int		main()
{
  t_server	server;
  int		port;

  port = 4042;
  signal(SIGINT, &sigint);
  atexit(clean);  
  if (server_init(&server, port))
    return (1);
  printf("Server listenning on: %d\n", port);
  while (42)
    {
      if (ftp_accept(&server))
	return (1);
    }
  return (0);
}
