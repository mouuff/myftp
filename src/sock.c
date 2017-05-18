/*
** sock.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Wed May 17 11:56:13 2017 arnaud.alies
** Last update Thu May 18 10:19:36 2017 arnaud.alies
*/

#include <unistd.h>
#include <string.h>
#include "server.h"

int             sock_send(int sockfd, char *str)
{
  int           size;

  size = strlen(str);
  if ((write(sockfd, str, size)) != size)
    return (1);
  if (write(sockfd, "\r\n", 2) != 2)
    return (1);
  return (0);
}
