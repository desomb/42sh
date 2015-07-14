/*
** path.c for 42sh in /home/colin_h/rendu/On_going_project/lexer_42/source/parser
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Thu May 21 15:19:00 2015 François Colin
** Last update Sun May 24 23:06:24 2015 François Colin
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my_str_to_wordtab.h"
#include "pars.h"
#include "list.h"
#include "my.h"

t_pars          *pars_path(t_pars *pars, char **env, int a)
{
  if ((pars->path = malloc(sizeof(char) * my_strlen(env[a]) + 1)) == NULL)
    return (NULL);
  return (pars);
}

char	*finish_path(t_pars *pars, int j)
{
  char	*str;

  pars->path[j] = '\0';
  str = my_strcat(pars->path, "/");
  free(pars->path);
  pars->path = str;
  str = my_strcat(pars->path, pars->tab[0]);
  free(pars->path);
  pars->path = str;
  return (pars->path);
}

t_pars          *my_path_access(t_pars *pars, char **env, int a)
{
  int           i;
  int           j;

  j = 0;
  i = 0;
  while (env[a][i])
    {
      j = 0;
      while (env[a][i] != '/')
        i++;
      if ((pars->path = malloc(sizeof(char) * my_strlen(env[a]) + 1)) == NULL)
	return (NULL);
      while (env[a][i] != ':' && env[a][i] != '\0')
        {
          pars->path[j] = env[a][i++];
          j++;
        }
      pars->path = finish_path(pars, j);
      if (access(pars->path, X_OK) == 0)
        return (pars);
      else
        pars = pars_path(pars, env, a);
    }
  pars->path = NULL;
  return (pars);
}

t_pars          *my_path_remp(t_struct *struc, char **env, t_pars *pars, int i)
{
  if (struc->instruction != NULL)
    if (!(pars->path = malloc(sizeof(char) *
			      (my_strlen(struc->instruction) + 10))))
      return (NULL);
  if (my_strncmp(struc->instruction, "./", 2) == 0)
    return (my_relativ_path(struc, pars));
  while (env[i])
    {
      if (my_global_path(struc) == 0)
        {
          pars = my_global_remp(pars, struc);
          break;
        }
      if (my_strncmp(env[i], "PATH=", 5) == 0)
	return (my_path_access(pars, env, i));
      else
	{
	  free(pars->path);
	  pars->path = NULL;
	}
      i++;
    }
  return (pars);
}

int     my_global_path(t_struct *struc)
{
  if (my_strncmp(struc->instruction, "/bin/", 5) == 0)
    return (0);
  if (my_strncmp(struc->instruction, "/usr/bin/", 9) == 0)
    return (0);
  if (my_strncmp(struc->instruction, "/usr/sbin/", 10) == 0)
    return (0);
  if (my_strncmp(struc->instruction, "/sbin/", 6) == 0)
    return (0);
  return (1);
}
