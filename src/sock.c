/*
** server.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Sat May 13 16:30:04 2017 arnaud.alies
** Last update Sun May 14 12:15:13 2017 arnaud.alies
*/

#include "server.h"

int     sock_init(t_sock *sock, int port)
{
  (sock->port) = port;
  if ((sock->proto = getprotobyname("TCP")) == NULL)
    return (1);
  (sock->addr).sin_family = AF_INET;
  (sock->addr).sin_port = htons((sock->port));
  (sock->addr).sin_addr.s_addr = INADDR_ANY;
  if (((sock->fd) = socket(AF_INET, SOCK_STREAM, (sock->proto)->p_proto)) == -1)
    return (1);
  clean_add_fd(sock->fd);
  if ((bind((sock->fd),
            (const struct sockaddr*)&(sock->addr),
            sizeof((sock->addr)))) == -1)
    return (1);
  if (listen(sock->fd, MAX_CLIENTS) == -1)
    return (1);
  return (0);
}

int     sock_accept(t_client *client, t_sock const *sock)
{
  client->addrlen = sizeof(client->addr);
  if ((client->fd = accept(sock->fd,
                           (struct sockaddr*)&(client->addr),
                           &(client->addrlen))) == -1)
    return (1);
  return (0);
}
