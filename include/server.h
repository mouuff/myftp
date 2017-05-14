/*
** server.h for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:50 2017 arnaud.alies
** Last update Sun May 14 15:51:35 2017 arnaud.alies
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

#define MAX_CLIENTS (42)
#define BUFF_SIZE (256)

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
** Command
*/

typedef int(*t_cmd_handler)(t_ftp *ftp, char *cmd);

typedef struct s_cmd
{
  char const *str;
  t_cmd_handler func;
} t_cmd;

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
