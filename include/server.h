/*
** server.h for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Fri May 12 15:08:50 2017 arnaud.alies
** Last update Thu May 18 16:26:01 2017 arnaud.alies
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
#include "my.h"

#define GETBYTE(var, x) (((var) >> ((x) * 8)) & 0xff)
#define IARG(args, x) (atoi((args->av)[x]))
#define MAX_CLIENTS (42)
#define BUFF_SIZE (2048)

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

typedef enum e_mode
  {
    M_PASV = 1,
    M_PORT,
    M_NO
  } t_mode;

typedef enum e_code
  {
    FTP_NOCODE = 0,
    FTP_FILEOK = 150,
    FTP_RDY = 220,
    FTP_CLOSING = 221,
    FTP_OK = 200,
    FTP_HELP = 214,
    FTP_CLOSING_DATA = 226,
    FTP_PASV = 227,
    FTP_LOGGED = 230,
    FTP_COMPLETED = 250,
    FTP_CREATED = 257,
    FTP_NEED_PASS = 331,
    FTP_NEED_ACC = 332,
    FTP_PWD = 257,
    FTP_SYNTAX = 500,
    FTP_NOT_LOGGED = 530,
    FTP_FAIL = 550,
    FTP_CANT_DATA = 425
  } t_code;

typedef struct s_ftp
{
  t_server *server;
  t_client *client;
  t_mode mode;
  bool anonymous;
  bool logged;
  bool running;
} t_ftp;

/*
** Command
*/

#define DEF_CMD(cmd) {#cmd, cmd_##cmd}

typedef int(*t_cmd_handler)(t_ftp *ftp, t_args *args);

typedef struct s_cmd
{
  char const *str;
  t_cmd_handler func;
} t_cmd;

int cmd_user(t_ftp *ftp, t_args *args);
int cmd_pass(t_ftp *ftp, t_args *args);
int cmd_quit(t_ftp *ftp, t_args *args);

int cmd_pwd(t_ftp *ftp, t_args *args);
int cmd_cdup(t_ftp *ftp, t_args *args);
int cmd_noop(t_ftp *ftp, t_args *args);
int cmd_help(t_ftp *ftp, t_args *args);
int cmd_cwd(t_ftp *ftp, t_args *args);
int cmd_pasv(t_ftp *ftp, t_args *args);
int cmd_port(t_ftp *ftp, t_args *args);
int cmd_list(t_ftp *ftp, t_args *args);
int cmd_dele(t_ftp *ftp, t_args *args);
int cmd_retr(t_ftp *ftp, t_args *args);

int cmd_run(t_ftp *ftp, char *cmd);

/*
** Server
*/

int     server_init(t_server *server, int port, bool reuse);
int     server_accept(t_client *client, t_server const *server);
int	sock_send(int sockfd, char *str);

/*
** FTP server
*/

int	ftp_passive(int *port);
int     ftp_passive_fd();
int	ftp_port(char *str);
int     ftp_port_fd();


int	ftp_mode_fd(t_ftp *ftp);

int     ftp_read(t_ftp *ftp, char *buff, size_t size);
int	ftp_send(t_ftp *ftp, t_code code, char *str);
int	ftp_accept(t_server *server, char *home);


/*
** Cleaner
*/

void clean_add_fd(int fd);
void clean_close_fd(int fd);
void clean();

#endif
