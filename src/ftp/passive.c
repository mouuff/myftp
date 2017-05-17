/*
** passive.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed May 17 14:26:18 2017 arnaud.alies
** Last update Wed May 17 22:29:08 2017 arnaud.alies
*/

#include "server.h"

static t_server g_server;
static bool g_openned = false;

int	ftp_passive_fd(t_server *server, t_client *client)
{
  client->addrlen = sizeof(client->addr);
  if ((client->fd = accept(server->fd,
                           (struct sockaddr*)&(client->addr),
                           &(client->addrlen))) < 0)
    {
      clean_close_fd(server->fd);
      g_openned = false;
      return (-1);
    }
  clean_close_fd(server->fd);
  g_openned = false;
  return (client->fd);
}

int		ftp_passive(int *port)
{
  socklen_t	len;

  if (g_openned == true)
    clean_close_fd(g_server.fd);
  if (port == NULL)
    return (1);
  g_openned = false;
  *port = 0;
  if (server_init(&g_server, 0, false))
    {
      clean_close_fd(g_server.fd);
      return (1);
    }
  g_openned = true;
  len = sizeof(g_server.addr);
  if (getsockname(g_server.fd, (struct sockaddr*)&(g_server.addr), &len) < 0)
    {
      clean_close_fd(g_server.fd);
      g_openned = false;
      return (1);
    }
  *port = ntohs(g_server.addr.sin_port);
  return (0);
}
