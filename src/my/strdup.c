/*
** strdup.c for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
** 
** Made by arnaud.alies
** Login   <arnaud.alies@epitech.eu>
** 
** Started on  Tue May 16 09:44:50 2017 arnaud.alies
** Last update Tue May 16 09:46:03 2017 arnaud.alies
*/

#include <string.h>
#include "my.h"

char	*my_strdup(const char *str)
{
  char	*res;

  res = my_malloc(sizeof(char) * (strlen(str) + 1));
  memcpy(res, str, strlen(str));
  return (res);
}
