/*
** my_strcapitalize.c for my_strcapitalize in /home/colin_h/rendu/Piscine_C_J06
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct 20 13:49:18 2014 François Colin
** Last update Fri Oct 24 11:55:39 2014 François Colin
*/

#include "my.h"

char	*my_strcapitalize(char *str)
{
  int i;
  char *str2;

  i = 0;
  str2 = my_strdup(str);
  while (str2[i] != '\0')
    {
      if (str2[i] >= 'a' && str2[i] <= 'z')
 	{
	  if (str2[i - 1] >= '0' && str2[i - 1] <= '9')
	    i = i + 1;
	  else
	    {
	      str2[i] = str2[i] - 32;
	      i = i + 1;
	    }
	  while (str2[i] >= 'a' && str2[i] <= 'z' && str[i] != '\0')
	    i = i + 1;
	}
      else
	i = i + 1;
    }
  return (str2);
}
