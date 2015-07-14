/*
** my_str_isalpha.c for my_str_isalpha in /home/colin_h/rendu/Piscine_C_J06/ex_10
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Thu Oct  9 22:00:03 2014 François Colin
** Last update Sun Nov 16 22:15:25 2014 François Colin
*/

#include "my.h"

int	my_str_isalpha(char *str)
{
  int i;

  i = 0;
  while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
    i = i + 1;
  if (i != my_strlen(str))
    return (0);
  return (1);
}
