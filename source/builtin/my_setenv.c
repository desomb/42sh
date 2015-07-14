/*
** my_setenv.c for minishell2 in /home/colin_h/rendu/On_going_project/PSU_2014_minishell2/ne_source
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Fri Mar  6 16:52:37 2015 François Colin
** Last update Sun May 24 22:58:22 2015 François Colin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_spe_strlen(char *option)
{
  int i;

  i = 0;
  if (option)
    {
      while (option[i] != '\0' && option[i] != ' ')
	i++;
    }
  return (i);
}

char	**my_change_var(char **my_env, int i, char *option, int len)
{
  if ((my_env[i] = malloc(sizeof(char) * (my_strlen(option) + 2))) == NULL)
      return (NULL);
  my_env[i] = my_strncpy(my_env[i], option, len);
  my_env[i][len] = '=';
  my_strcpy(&my_env[i][len + 1], &option[len + 1]);
  my_env[i][my_strlen(option)] = '\0';
  return (my_env);
}

char	**create_new_var(char **my_env, int i, char *option, int len)
{
  int j;
  char **tab;

  j = 0;
  if ((tab = malloc(sizeof(char *) * (i + 2))) == NULL)
    return (NULL);
  while (my_env[j] != NULL)
    {
      tab[j] = my_strcat(NULL, my_env[j]);
      free(my_env[j]);
      j++;
    }
  free(my_env[j]);
  free(my_env);
  tab = my_change_var(tab, j, option, len);
  tab[j + 1] = NULL;
  return (tab);
}

char	**my_setenv(char **my_env, char *option)
{
  int len;
  int i;

  i = 0;
  len = my_spe_strlen(option);
  while (my_env[i] != NULL && my_strncmp(my_env[i], option, len-1) == 1)
    i++;
  if (my_env[i] != NULL)
    {
      free(my_env[i]);
      my_env = my_change_var(my_env, i, option, len);
    }
  else
    my_env = create_new_var(my_env, i, option, len);
  return (my_env);
}
