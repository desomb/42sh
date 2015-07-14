/*
** my_strlowcase.c for my_strlowcase in /home/colin_h/rendu/Piscine_C_J06/ex_08
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct 20 13:39:30 2014 François Colin
** Last update Fri Oct 24 11:54:45 2014 François Colin
*/

#include "my.h"

char    *my_strupcase(char *str)
{
  int i;
  char *str2;

  str2 = my_strdup(str);
  i = 0;
  while (str[i] != '\0')
    {
      if (str2[i] >= 'A' && str2[i] <= 'Z')
        str2[i] = str2[i] + 32;
      i = i + 1;
    }
  return (str2);
}
