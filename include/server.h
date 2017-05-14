/*
** server.h for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:50 2017 arnaud.alies
** Last update Sun May 14 11:54:54 2017 arnaud.alies
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

typedef struct s_sock
{
  struct protoent *proto;
  struct sockaddr_in addr;
  int fd;
  int port;
} t_sock;

typedef struct s_client
{
  int fd;
  struct sockaddr_in addr;
  socklen_t addrlen;
} t_client;

void    *xmalloc(size_t size);

/*
** Sock
*/

int     sock_init(t_sock *sock, int port);
int     sock_accept(t_client *client, t_sock const *sock);

/*
** Cleaner
*/

void clean_add_fd(int fd);
void clean_close_fd(int fd);
void clean();

#endif
