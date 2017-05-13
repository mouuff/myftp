/*
** main.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:36 2017 arnaud.alies
** Last update Sat May 13 13:03:21 2017 arnaud.alies
*/

#include "server.h"

int	server_init(t_server *server, int port)
{
  (server->port) = port;
  if ((server->pe = getprotobyname("TCP")) == NULL)
    return (1);
  (server->in).sin_family = AF_INET;
  (server->in).sin_port = htons((server->port));
  (server->in).sin_addr.s_addr = INADDR_ANY;
  if (((server->fd) = socket(AF_INET, SOCK_STREAM, (server->pe)->p_proto)) == -1)
    return (1);
  clean_add_fd(server->fd);
  if ((bind((server->fd),
	    (const struct sockaddr*)&(server->in),
	    sizeof((server->in)))) == -1)
    return (1);
  if (listen(server->fd, MAX_CLIENTS) == -1)
    return (1);
  return (0);
}


int		main()
{
  t_server	server;
  
  if ((server_init(&server, 4242)) == -1)
    return (1);
  atexit(clean);
  return (0);
}
