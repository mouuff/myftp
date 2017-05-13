/*
** main.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:36 2017 arnaud.alies
** Last update Sat May 13 18:37:30 2017 arnaud.alies
*/

#include "server.h"

int		serve(t_server *server)
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
  return (0);
}

int		main()
{
  t_server	server;

  atexit(clean);  
  if ((server_init(&server, 4242)) == -1)
    return (1);
  while (42)
    {
      if (serve(&server) == 1)
	return (1);
    }
  return (0);
}
