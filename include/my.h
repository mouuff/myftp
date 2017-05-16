/*
** my.h for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Mon May 15 19:01:51 2017 arnaud.alies
** Last update Tue May 16 09:44:31 2017 arnaud.alies
*/

#ifndef MY_H_
# define MY_H_

#include <stdlib.h>

typedef struct s_args
{
  int ac;
  char **av;
} t_args;

void *my_malloc(size_t size);
char *my_strdup(const char *str);

t_args *my_str_args(char const *str);

#endif