/*
** my_unsetenv.c for minishell2 in /home/colin_h/rendu/On_going_project/PSU_2014_minishell2/ne_source
**
** Made by François Colin
** Login   <colin_h@epitech.net>
**
** Started on  Fri May 22 14:46:10 2015 François Colin
** Last update Sun May 24 22:48:57 2015 Vincent Desombre
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_free.h"
#include "my.h"

char **my_fill_env(char **tab, char **my_env, int var_nbr)
{
  while (my_env[var_nbr] != NULL)
    {
      tab[var_nbr] = my_strcat(NULL, my_env[var_nbr]);
      free(my_env[var_nbr]);
      var_nbr++;
    }
  free(my_env[var_nbr]);
  var_nbr++;
  while (my_env[var_nbr] != NULL)
    {
      tab[var_nbr - 1] = my_strcat(NULL, my_env[var_nbr]);
      free(my_env[var_nbr]);
      var_nbr++;
    }
  free(my_env[var_nbr]);
  tab[var_nbr - 1] = NULL;
  return (tab);
}

char    **my_actualize_env(char **my_env)
{
  char	**tab;
  int	var_nbr;

  var_nbr = 0;
  while (my_env[var_nbr] != NULL)
    var_nbr++;
  var_nbr++;
  while (my_env[var_nbr] != NULL)
    var_nbr++;
  if ((tab = malloc(sizeof(char *) * (var_nbr))) == NULL)
    return (NULL);
  var_nbr = 0;
  tab = my_fill_env(tab, my_env, var_nbr);
  free(my_env);
  return (tab);
}

char **my_unsetenv(char **my_env, char *option)
{
  int len;
  int i;

  i = 0;
  len = my_strlen(option) - 1;
  if (!my_env)
    return (NULL);
  while (my_env[i] != NULL && my_strncmp(my_env[i], option, len) != 0)
    i++;
  if (my_env[i] != NULL && my_strncmp(my_env[i], option, len) == 0)
    {
      free(my_env[i]);
      my_env[i] = NULL;
      my_env = my_actualize_env(my_env);
    }
  return (my_env);
}
