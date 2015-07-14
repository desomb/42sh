/*
** epur_space.c for epur_space in /media/quero_q/MYLINUXLIVE/progra/42/v2_42/source
**
** Made by quero_q
** Login   <quero_q@epitech.net>
**
** Started on  Tue May 19 18:15:00 2015 quero_q
** Last update Sat May 23 23:50:25 2015 François Colin
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char 	  *no_space(char *res, char *str)
{
  int	  i;
  int 	j;

  i = j = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  res[j] = str[i];
	  i++;
	  j++;
	}
      else
	i++;
    }
  res[j] = 0;
  return (res);
}

char    *epur_space(char *str)
{
  char  *res;

  if ((res = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  res = no_space(res, str);
  return (res);
}
