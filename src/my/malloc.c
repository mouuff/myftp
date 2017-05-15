/*
** my_malloc.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Mon May 15 18:58:11 2017 arnaud.alies
** Last update Mon May 15 19:08:02 2017 arnaud.alies
*/

#include <stdlib.h>
#include <string.h>

void    *my_malloc(size_t size)
{
  void  *res;

  res = malloc(size);
  if (res == NULL)
    exit(1);
  memset(res, 0, size);
  return (res);
}
