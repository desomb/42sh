/*
** my_putstrt.c for my_putstr.c in /home/colin_h/test/Day04/ex2
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Thu Oct  2 13:08:28 2014 François Colin
** Last update Thu Apr 23 14:32:06 2015 François Colin
*/

#include "my.h"

int	my_putstr(char *str)
{
  int i;

  i = 0;
  if (str)
    while (str[i])
      {
	my_putchar(str[i]);
	i  = i + 1;
      }
  return (i);
}
