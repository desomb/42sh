/*
** my_revstr.c for my_revstr.c in /home/colin_h/test/Day6
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct  6 13:48:21 2014 François Colin
** Last update Sun Nov 16 21:47:57 2014 François Colin
*/

#include "my.h"

int     my_strlen2(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

int     my_swapi(char *a, char *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}

char    *my_revstr(char *str)
{
  int	i;
  int	len;
  char	*str2;
  char	*str3;

  i = my_strlen2(str);
  len = i;
  str2 = str + i - 1;
  str3 = str;
  while (i > len/2)
    {
      my_swapi(str, str2);
      str = str + 1;
      str2 = str2 - 1;
      i = i - 1;
    }
  return (str3);
}
