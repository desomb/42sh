/*
** my_str_isprintable.c for my_str_isprintable in /home/colin_h/rendu/Piscine_C_J06/ex_14
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct 20 14:28:23 2014 François Colin
** Last update Sun Nov 16 22:22:15 2014 François Colin
*/

#include "my.h"

int	my_str_isprintable(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] > 126)
	return (0);
      i = i + 1;
    }
  return (1);
}
