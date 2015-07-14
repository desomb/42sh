/*
** my_str_isnum.c for my_str_isnum in /home/colin_h/rendu/Piscine_C_J06/ex_11
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Thu Oct  9 22:36:39 2014 François Colin
** Last update Sun Nov 16 22:16:46 2014 François Colin
*/

#include "my.h"

int	my_str_isnum(char *str)
{
  int i;

  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    i = i + 1;
  if (i != my_strlen(str))
    return (0);
  return (1);
}
