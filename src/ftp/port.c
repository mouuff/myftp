/*
** port.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Thu May 18 10:35:26 2017 arnaud.alies
** Last update Fri May 19 15:44:52 2017 arnaud.alies
*/

#include "server.h"

static int g_fd = -1;
static int g_port = 0;
static uint32_t g_ip = 0;

static int	get_ip_port(char *str)
{
  t_args	*args;

  g_port = 0;
  g_ip = 0;
  args = my_str_args(str, ",");
  if (args->ac != 6)
    {
      my_free_str_args(args);
      return (1);
    }
  g_port = (IARG(args, 4) << 8) + IARG(args, 5);
  g_ip = IARG(args, 0);
  g_ip += IARG(args, 1) << 8;
  g_ip += IARG(args, 2) << 16;
  g_ip += IARG(args, 3) << 24;
  my_free_str_args(args);
  return (0);
}

static int		connect_to_server(uint32_t ip, int port)
{
  struct sockaddr_in	serveraddr;
  struct protoent	*proto;
  int			sockfd;

  g_fd = -1;
  if ((proto = getprotobyname("TCP")) == NULL)
    return (1);
  if ((sockfd = socket(AF_INET, SOCK_STREAM, proto->p_proto)) < 0)
    return (1);
  clean_add_fd(sockfd);
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(port);
  serveraddr.sin_addr.s_addr = ip;
  if (connect(sockfd,
	      (const struct sockaddr*)&serveraddr,
	      sizeof(struct sockaddr_in)) < 0)
    {
      clean_close_fd(sockfd);
      return (1);
    }
  g_fd = sockfd;
  return (0);
}

int	ftp_port_fd()
{
  if (g_port == 0 || g_ip == 0)
    return (-1);
  connect_to_server(g_ip, g_port);
  return (g_fd);
}

int		ftp_port(char *str)
{
  clean_close_fd(g_fd);
  if (str == NULL)
    return (1);
  if (get_ip_port(str))
    return (1);
  return (0);
}
