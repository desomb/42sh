/*
** get_my_env.c for minishell2 in /home/colin_h/rendu/On_going_project/PSU_2014_minishell2/ne_source
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Thu Mar  5 14:59:59 2015 François Colin
** Last update Sun May 24 22:57:33 2015 François Colin
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void	aff_my_env(char **tab)
{
  int i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}

void	my_free_env(char **my_env)
{
  int i;

  i = 0;
  while (my_env[i] != NULL)
    {
      free(my_env[i]);
      i++;
    }
  free(my_env[i]);
  free(my_env);
}

char	**my_getenv(char **environ)
{
  char **tab;
  int var_nbr;

  var_nbr = 0;
  while (environ[var_nbr] != NULL)
    var_nbr++;
  if ((tab = malloc(sizeof(char *) * (var_nbr + 1))) == NULL)
    return (NULL);
  tab[var_nbr] = NULL;
  var_nbr = 0;
  while (environ[var_nbr] != NULL)
    {
      tab[var_nbr] = my_strcat(NULL, environ[var_nbr]);
      var_nbr++;
    }
  environ[var_nbr] = NULL;
  return (tab);
}
