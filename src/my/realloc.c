/*
** realloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue May 16 17:40:30 2017 arnaud.alies
** Last update Tue May 16 17:43:26 2017 arnaud.alies
*/

#include <stdlib.h>

void	*my_realloc(void *ptr, size_t size)
{
  void	*res;

  if (size == 0)
    return (ptr);
  res = realloc(ptr, size);
  if (res == NULL)
    exit(1);
  return (res);
}
