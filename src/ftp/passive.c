/*
** passive.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed May 17 14:26:18 2017 arnaud.alies
** Last update Wed May 17 17:32:13 2017 arnaud.alies
*/

#include "server.h"

static t_server g_server;
static bool g_openned = false;

static int	passive_init(t_server *server)
{
  (server->port) = 0;
  if ((server->proto = getprotobyname("TCP")) == NULL)
    return (1);
  (server->addr).sin_family = AF_INET;
  (server->addr).sin_port = htons((server->port));
  (server->addr).sin_addr.s_addr = INADDR_ANY;
  if (((server->fd) = socket(AF_INET, SOCK_STREAM,
			     (server->proto)->p_proto)) < 0)
    return (1);
  if ((bind((server->fd),
            (const struct sockaddr*)&(server->addr),
            sizeof((server->addr)))) < 0)
    {
      close(server->fd);
      return (1);
    }
  if (listen(server->fd, MAX_CLIENTS) < 0)
    {
      close(server->fd);
      return (1);
    }
  g_openned = true;
  return (0);
}

int	ftp_passive_fd(t_server *server, t_client *client)
{
  client->addrlen = sizeof(client->addr);
  if ((client->fd = accept(server->fd,
                           (struct sockaddr*)&(client->addr),
                           &(client->addrlen))) < 0)
    {
      close(server->fd);
      g_openned = false;
      return (-1);
    }
  close(server->fd);
  g_openned = false;
  return (client->fd);
}

int		ftp_passive(int *port)
{
  socklen_t	len;

  *port = 0;
  if (passive_init(&g_server))
    return (1);
  len = sizeof(g_server.addr);
  if (getsockname(g_server.fd, (struct sockaddr*)&(g_server.addr), &len) < 0)
    {
      close(g_server.fd);
      g_openned = false;
      return (1);
    }
  *port = ntohs(g_server.addr.sin_port);
  return (0);
}
