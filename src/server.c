/*
** server.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Sat May 13 16:30:04 2017 arnaud.alies
** Last update Mon May 15 17:13:29 2017 arnaud.alies
*/

#include <unistd.h>
#include <string.h>
#include "server.h"

int     server_init(t_server *server, int port)
{
  int	enable;

  (server->port) = port;
  if ((server->proto = getprotobyname("TCP")) == NULL)
    return (1);
  (server->addr).sin_family = AF_INET;
  (server->addr).sin_port = htons((server->port));
  (server->addr).sin_addr.s_addr = INADDR_ANY;
  if (((server->fd) = socket(AF_INET, SOCK_STREAM, (server->proto)->p_proto)) < 0)
    return (1);
  clean_add_fd(server->fd);
  enable = 1;
  if (setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
    return (1);
  if ((bind((server->fd),
            (const struct sockaddr*)&(server->addr),
            sizeof((server->addr)))) < 0)
    return (1);
  if (listen(server->fd, MAX_CLIENTS) < 0)
    return (1);
  return (0);
}

int     server_accept(t_client *client, t_server const *server)
{
  client->addrlen = sizeof(client->addr);
  if ((client->fd = accept(server->fd,
                           (struct sockaddr*)&(client->addr),
                           &(client->addrlen))) < 0)
    return (1);
  clean_add_fd(client->fd);
  return (0);
}

int		server_send(int sockfd, char *str)
{
  int		size;

  size = strlen(str);
  if ((write(sockfd, str, size)) != size)
    return (1);
  if (write(sockfd, "\r\n", 2) != 2)
    return (1);
  return (0);
}
