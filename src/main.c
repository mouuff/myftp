/*
** main.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:36 2017 arnaud.alies
** Last update Sat May 13 16:25:06 2017 arnaud.alies
*/

#include "server.h"

int	server_init(t_server *server, int port)
{
  (server->port) = port;
  if ((server->pe = getprotobyname("TCP")) == NULL)
    return (1);
  (server->addr).sin_family = AF_INET;
  (server->addr).sin_port = htons((server->port));
  (server->addr).sin_addr.s_addr = INADDR_ANY;
  if (((server->fd) = socket(AF_INET, SOCK_STREAM, (server->pe)->p_proto)) == -1)
    return (1);
  clean_add_fd(server->fd);
  if ((bind((server->fd),
	    (const struct sockaddr*)&(server->addr),
	    sizeof((server->addr)))) == -1)
    return (1);
  if (listen(server->fd, MAX_CLIENTS) == -1)
    return (1);
  return (0);
}

int	server_accept(t_client *client, t_server *server)
{
  client->addrlen = sizeof(client->addr);
  if ((client->fd = accept(server->fd,
			   (struct sockaddr*)&(client->addr),
			   &(client->addrlen))) == -1)
    return (1);
  return (0);
}

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
