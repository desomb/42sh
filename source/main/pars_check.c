/*
** pars_check.c for pars_check in /home/quero_q/Dropbox/progra/42
**
** Made by quero_q
** Login   <quero_q@epitech.net>
**
** Started on  Tue May 12 14:24:54 2015 quero_q
** Last update Sun May 24 20:11:59 2015 François Colin
*/

#include <stdio.h>
#include <stdlib.h>
#include "epur_space.h"
#include "error.h"

int     check_char(char *str, char c, int max)
{
  int	i;
  int 	j;

  j = i = 0;
  while (str[i])
    {
      if (str[i] == c)
	{
	  j++;
	  if (j >= max + 1)
	    return (-1);
	}
      if (str[i] != c)
	j = 0;
      i++;
    }
  return (0);
}

char 	*check_param(char *str, char c)
{
  int	i;
  int 	j;

  i = j = 0;
  while (str[i])
    {
      if (str[i] == c)
	j++;
      i++;
    }
  if ((j % 2) == 0)
    return (str);
  else
    return (error_check(c));
}

char    *check_sep(char *str)
{
  char    *str2;
  char    *test;
  int i;

  i = 0;
  test = "|2&2<1>2;1";
  str2 = str;
  while (test[i])
    {
      if (check_char(str2, test[i], test[i + 1] - 48) == -1)
	return (error_check(test[i]));
      i += 2;
    }
  return (str);
}

char    *pars_check(char *str)
{
  char *str2;

  str2 = NULL;
  str2 = str;
  if (!str[0])
    return (NULL);
  str2 = epur_space(str2);
  if ((str2 = check_sep(str2)) == NULL)
    return (str2);
  free(str2);
  str2 = str;
  if ((str2 = check_param(str2, '"')) == NULL)
    return (str2);
  return (str);
}

void    clear_buff(char *s)
{
  int i;

  i = 0;
  while (s[i])
    s[i++] = 0;
}
