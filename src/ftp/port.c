/*
** port.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Thu May 18 10:35:26 2017 arnaud.alies
** Last update Thu May 18 12:39:55 2017 arnaud.alies
*/

#include "server.h"

static int g_fd = -1;

int	ftp_port_fd()
{
  return (g_fd);
}

static int	get_ip_port(char *str, uint32_t *ip, int *port)
{
  t_args	*args;

  *port = 0;
  *ip = 0;
  args = my_str_args(str, ",");
  if (args->ac != 6)
    {
      my_free_str_args(args);
      return (1);
    }
  *port = (IARG(args, 4) << 8) + IARG(args, 5);
  *ip = IARG(args, 0);
  *ip += IARG(args, 1) << 8;
  *ip += IARG(args, 2) << 16;
  *ip += IARG(args, 3) << 24;
  my_free_str_args(args);
  return (0);
}

static int		connect_to_server(uint32_t ip, int port)
{
  struct sockaddr_in	serveraddr;
  int			sockfd;
  struct protoent	*proto;

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

int		ftp_port(t_ftp *ftp, char *str)
{
  int		port;
  uint32_t	ip;

  clean_close_fd(g_fd);
  g_fd = -1;
  if (str == NULL)
    return (1);
  if (get_ip_port(str, &ip, &port))
    return (1);
  if (connect_to_server(ip, port))
    return (1);
  /*
  char		buff[BUFF_SIZE];
  sprintf(buff, "%d.%d.%d.%d : %d",
	  GETBYTE(ip, 0), GETBYTE(ip, 1),
	  GETBYTE(ip, 2), GETBYTE(ip, 3), port);
  return (ftp_send(ftp, FTP_NOCODE, buff));
  */
  return (0);
}
