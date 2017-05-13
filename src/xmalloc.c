/*
** xmalloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Sat May 13 11:39:02 2017 arnaud.alies
** Last update Sat May 13 11:42:41 2017 arnaud.alies
*/

#include <stdlib.h>

void	*xmalloc(size_t size)
{
  void	*res;

  res = malloc(size);
  if (res == NULL)
    exit(1);
  return (res);
}
