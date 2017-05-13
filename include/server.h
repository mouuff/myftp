/*
** server.h for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:50 2017 arnaud.alies
** Last update Sat May 13 15:46:50 2017 arnaud.alies
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_CLIENTS (42)

typedef struct s_server
{
  struct protoent *pe;
  struct sockaddr_in addr;
  int fd;
  int port;
} t_server;

typedef struct s_client
{
  int fd;
  struct sockaddr_in addr;
  socklen_t addrlen;
} t_client;

void    *xmalloc(size_t size);

/*
** Cleaner
*/

void clean_add_fd(int fd);
void clean_close_fd(int fd);
void clean();

#endif
