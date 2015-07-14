/*
** my_strdup.c for my_strdup in /home/colin_h/rendu/Piscine_C_J08/ex_01
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Wed Oct  8 09:02:27 2014 François Colin
** Last update Sun May 24 23:00:49 2015 Vincent Desombre
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  int len;
  char *src2;

  len = my_strlen(src);
  if ((src2 = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  src2[len] = '\0';
  my_strcpy(src2, src);
  return (src2);
}
