/*
** str_args.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue May 16 09:17:03 2017 arnaud.alies
** Last update Tue May 16 10:42:34 2017 arnaud.alies
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"

static int	char_count(char const *str, char c)
{
  int		x;
  int		res;

  x = 0;
  res = 0;
  while (str[x] != '\0')
    {
      if (str[x] == c)
	res += 1;
      x += 1;
    }
  return (res);
}

static void	args_add(t_args *args, char const *to_add, int *pos)
{
  if (*pos < args->ac)
    {
      args->av[*pos] = my_strdup(to_add);
      *pos += 1;
    }
}

t_args		*my_str_args(char const *str)
{
  t_args	*args;
  char		*copy;
  char		*buff;
  int		pos;

  pos = 0;
  copy = my_strdup(str);
  args = my_malloc(sizeof(t_args));
  args->ac = char_count(copy, ' ') + 1;
  args->av = my_malloc(sizeof(char*) * (args->ac + 1));
  buff = strtok(copy, " ");
  while (buff != NULL)
    {
      args_add(args, buff, &pos);
      buff = strtok(NULL, " ");
    }
  args->ac = pos;
  free(copy);
  return (args);
}

void		my_free_str_args(t_args *args)
{
  int		x;

  x = 0;
  while (x < args->ac)
    {
      free((args->av)[x]);
      x += 1;
    }
  free(args->av);
  free(args);
}
