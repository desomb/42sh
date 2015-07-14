/*
** epurstr.c for 42 in /home/colin_h/rendu/On_going_project/lexer_42
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Thu Apr 23 10:47:21 2015 François Colin
** Last update Sat May 23 15:23:10 2015 François Colin
*/

#include <stdlib.h>
#include "my_free.h"
#include "my.h"

int	my_str_properlen(char *str)
{
  int i;
  int len;

  i = 0;
  len = 0;
  while (str[i] != '\0')
    {
      if (i == 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'))
	  len = len;
      else if (str[i] != ' ' && str[i] != '\t' && str[i] != '\v')
	len++;
      else if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\v') &&
	  str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\v')
	len++;
      i++;
    }
  return (len);
}

char	*fill_res(char *str, char *res)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
  {
    if (i == 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'))
      j = j;
    else if (str[i] != ' ' && str[i] != '\t' && str[i] != '\v')
      res[j++] = str[i];
    else if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\v') &&
	     str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\v')
      res[j++] = ' ';
    i++;
  }
  if (j == 0)
    {
      free(res);
      return (NULL);
    }
  else
    if (res[j - 1] == ' ' || res[j - 1] == '\t' || res[j - 1] == '\v')
      res[j - 1] = '\0';
  return (res);
}

char	*my_epurstr(char *str)
{
  char *res;

  if ((res = malloc(sizeof(char) * (my_str_properlen(str) + 1))) == NULL)
    return (NULL);
  res[my_str_properlen(str)] = '\0';
  res = fill_res(str, res);
  return (res);
}
