/*
** my_strstr.c for my_strstr in /home/colin_h/test/Day6
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct  6 15:52:08 2014 François Colin
** Last update Wed Oct  8 16:55:56 2014 François Colin
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

char	*my_check(char *str, char *to_find)
{
  int i;
  int len;

  i = 0;
  len = my_strlen(to_find);
  while (str[i] == to_find[i])
    i = i + 1;
  if (i == len)
    return (&str[i]);
  return (0);
}

char	*my_strstr(char *str, char *to_find)
{
  int i;
  int j;
  char *k;
  char *p;

  p = NULL;
  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == to_find[j])
	{
	  k = my_check(&str[i], &to_find[j]);
	  if (k != 0)
	    return (&str[i]);
	}
      i = i + 1;
    }
  return (p);
}
