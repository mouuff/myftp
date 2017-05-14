/*
** server.h for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:50 2017 arnaud.alies
** Last update Sun May 14 14:15:12 2017 arnaud.alies
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
//#include <linux/limits.h>

#define MAX_CODE_SIZE (4)
#define MAX_CLIENTS (42)

typedef enum e_ret
  {
    OK = 0,
    KO
  } t_ret;

typedef struct s_server
{
  struct protoent *proto;
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

typedef struct s_ftp
{
  t_server *server;
  t_client *client;
  bool logged;
  bool running;
} t_ftp;

void    *xmalloc(size_t size);

/*
** Server
*/

int     server_init(t_server *server, int port);
int     server_accept(t_client *client, t_server const *server);
int	server_send(int sockfd, char *str);

/*
** FTP server
*/

int	ftp_accept(t_server *server);

/*
** Cleaner
*/

void clean_add_fd(int fd);
void clean_close_fd(int fd);
void clean();

#endif
