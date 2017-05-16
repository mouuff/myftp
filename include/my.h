/*
** my.h for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Mon May 15 19:01:51 2017 arnaud.alies
** Last update Tue May 16 17:43:47 2017 arnaud.alies
*/

#ifndef MY_H_
# define MY_H_

#include <stdlib.h>

#ifndef READ_SIZE
#define READ_SIZE (256)
#endif

typedef struct s_args
{
  int ac;
  char **av;
} t_args;

void *my_malloc(size_t size);
void *my_realloc(void *ptr, size_t size);
char *my_strdup(const char *str);

t_args *my_str_args(char const *str);
void my_free_str_args(t_args *args);

char *get_next_line(const int fd);

#endif
