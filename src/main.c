/*
** main.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:36 2017 arnaud.alies
** Last update Sat May 13 16:30:20 2017 arnaud.alies
*/

#include "server.h"

int		main()
{
  t_client	client;
  t_server	server;

  atexit(clean);  
  if ((server_init(&server, 4242)) == -1)
    return (1);
  if (server_accept(&client, &server) == -1)
    return (1);
  return (0);
}
