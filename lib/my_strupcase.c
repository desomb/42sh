/*
** my_strupcase.c for my_strupcase in /home/colin_h/rendu/Piscine_C_J06/ex_07
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct 20 11:36:59 2014 François Colin
** Last update Fri Oct 24 11:52:58 2014 François Colin
*/

#include "my.h"

char	*my_strupcase(char *str)
{
  int i;
  char *str2;

  str2 = my_strdup(str);
  i = 0;
  while (str[i] != '\0')
    {
      if (str2[i] >= 'a' && str2[i] <= 'z')
	str2[i] = str2[i] - 32;
      i = i + 1;
    }
  return (str2);
}
