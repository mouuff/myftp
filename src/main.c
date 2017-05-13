/*
** main.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:36 2017 arnaud.alies
** Last update Sat May 13 11:09:23 2017 arnaud.alies
*/

#include "server.h"

static t_server	server;

int	server_init(int port)
{
  (server.port) = port;
  if ((server.pe = getprotobyname("TCP")) == NULL)
    return (1);
  (server.in).sin_family = AF_INET;
  (server.in).sin_port = htons((server.port));
  (server.in).sin_addr.s_addr = INADDR_ANY;
  if (((server.fd) = socket(AF_INET, SOCK_STREAM, (server.pe)->p_proto)) == -1)
    return (1);
  if ((bind((server.fd), (const struct sockaddr*)&(server.in), sizeof((server.in)))) == -1)
    return (1);
  return (0);
}


int		main()
{
  if ((server_init(4242)) == -1)
    return (1);
  //atexit(server_close);
  return (0);
}
