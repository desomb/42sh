/*
** my_builtin.c for my_cd in /home/thomaz_a/rendu/Semestre-2/PSU/PSU_2014_minishell2
**
** Made by Arnaud Thomazo
** Login   <thomaz_a@epitech.net>
**
** Started on  Thu May 21 14:12:07 2015 Arnaud Thomazo
** Last update Thu May 28 17:23:12 2015 François Colin
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_setenv.h"
#include "my_cd.h"
#include "my.h"
#include "error.h"

int   find_pwd(char **env)
{
  int i;
  int j;

  i = j = 0;
  if (env != NULL)
    {
      while (env[i] != NULL)
	{
	  if (my_strncmp(env[i], "OLDPWD=", 7) == 0 && my_strlen(env[i]) > 7)
	    {
	      j++;
	    }
	  i++;
	}
      i = 0;
      while (env[i] != NULL)
	{
	  if (my_strncmp(env[i], "PWD=", 4) == 0 && my_strlen(env[i]) > 4)
	    j++;
	  i++;
	}
    }
  return (j);
}

char    ***my_cd(char **tab, char ***env)
{
  int   i;
  char  *oldpwd;
  char  *home;

  i = 0;
  oldpwd = new_pwd(*env, "OLDPWD=/");
  home = new_pwd(*env, "HOME=/");
  if ((my_strcmp("cd\0", tab[0]) == 0 && tab[1] == NULL) ||
  (my_strcmp("cd\0", tab[0]) == 0 && my_strcmp("--", tab[1]) == 0))
  chdir(home);
  else if (((my_strcmp(tab[0], "cd") == 0 && my_strcmp("-", tab[1]) != 0))
    && ((chdir(tab[1]) != 0 && ++i > 0)))
  error_cd(tab[1]);
  else if (my_strcmp("cd\0", tab[0]) == 0 &&
  my_strcmp("-", tab[1]) == 0 && find_pwd(*env) == 2)
    {
      if (chdir(oldpwd) != 0 && ++i > 0)
	error_cd(oldpwd);
      my_putstr(oldpwd);
      my_putchar('\n');
    }
  if (i == 0 && find_pwd(*env) == 2)
    *env = change_oldpwd(*env);
  return (env);
}

char    *new_pwd(char **env, char *str)
{
  int   i;
  int   j;
  int   y;
  char  *newstr;

  i = 1;
  j = 0;
  y = 0;
  while (env[i])
    {
      if (my_strncmp(str , env[i], my_strlen(str)) == 0)
	{
	  while (env[i][j] != '/')
	    j++;
	  if ((newstr = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
	    return (NULL);
	  while (env[i][j])
	    newstr[y++] = env[i][j++];
	  newstr[y] = '\0';
	}
      i++;
    }
  return (newstr);
}

char    **change_oldpwd(char **env)
{
  char  *oldpwd;
  char  *pwd;

  if ((pwd = malloc(sizeof(char *) * 1024)) == NULL)
    return (NULL);
  oldpwd = new_pwd(env, "PWD=/");
  if (getcwd(pwd, 1024) == NULL)
    {
      pwd = new_pwd(env, "OLDPWD=/");
      error_cd(pwd);
    }
  pwd = my_strcat("PWD ", pwd);
  oldpwd = my_strcat("OLDPWD ", oldpwd);
  env = my_setenv(env, pwd);
  env = my_setenv(env, oldpwd);
  if (pwd != NULL)
    free(pwd);
  if (oldpwd != NULL)
    free(oldpwd);
  return (env);
}
