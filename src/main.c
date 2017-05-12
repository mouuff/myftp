/*
** main.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:36 2017 arnaud.alies
** Last update Fri May 12 18:14:25 2017 arnaud.alies
*/

#include "server.h"

int		main()
{
  t_server	server;

  (server.port) = 4242;
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
