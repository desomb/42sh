/*
** my_str_to_wordtab.c for wordtab in /home/desomb_v/rendu/Piscine/Piscine_C_J08/ex4
**
** Made by Vincent Desombre
** Login   <desomb_v@epitech.net>
**
** Started on  Sun Jan 25 16:59:49 2015 Vincent Desombre
** Last update Sun May 24 19:53:46 2015 Vincent Desombre
*/

#include <stdlib.h>
#include "my.h"

int	countword(char *str)
{
  int	a;
  int	i;

  i = 0;
  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] == '"')
	{
	  while (str[++a] != '"');
	  i++;
	}
      if (str[a] == ' ')
	i++;
      a++;
    }
  return (i + 1);
}

int	countchar(char *str, int i)
{
  while (str[i] != '\0' && str[i] != ' ')
    {
      if (str[i] == '"')
	while (str[++i] != '"');
      if (str[i] != '\0')
	i++;
    }
  if (str[i - 1] == '"')
    i = i + 2;
  return (i);
}

void	check_end(char *str, int *i, int *y)
{
  if (str[*i] == ' ' || str[*i] == '\0' || str[*i] == '"')
    *y = *y + 1;
  if (str[*i] != '\0')
    *i = *i + 1;
}

void	aff_wordtab(char **str, int y)
{
  int	i;

  i = 0;
  my_put_nbr(y);
  while (str[i])
    {
      my_putstr(str[i]);
      my_putchar('\n');
      i++;
    }
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	y;
  int	x;

  i = 0;
  y = 0;
  if ((tab = malloc(sizeof(char *) * (countword(str) + 2))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      x = 0;
      if ((tab[y] = calloc((sizeof(char)* (countchar(str, i) + 2)), 1))== NULL)
	return (NULL);
      if (str[i] == '"')
	while (str[++i] != '"')
	tab[y][x++] = str[i];
      else
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n')
	tab[y][x++] = str[i++];
      tab[y][x] = '\0';
      check_end(str, &i, &y);
    }
  tab[y] = NULL;
  return (tab);
}
