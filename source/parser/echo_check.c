/*
** echo_check.c for echo in /home/desomb_v/rendu/Projet/PSU/PSU_2014_42sh/source/parser
**
** Made by Vincent Desombre
** Login   <desomb_v@epitech.net>
**
** Started on  Fri May 22 18:27:24 2015 Vincent Desombre
** Last update Sun May 24 23:07:12 2015 Vincent Desombre
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "pars.h"
#include "list.h"
#include "my.h"

char	*my_check_str(char *str)
{
  int	i;
  int	j;
  char	*str2;

  str2 = NULL;
  if ((str2 = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  i = j = 0;
  while (str[i] != '"' && str[i])
    i++;
  if (!str[i])
    {
      free(str2);
      return (str);
    }
  i++;
  while (str[i] && str[i] != '"')
    str2[j++] = str[i++];
  str2[j] = 0;
  return (str2);
}

char	**init_tab2(t_struct *struc, t_pars *pars)
{
  char	**tab2;

  if ((tab2 = malloc(sizeof(char*) * 3)) == NULL)
    return (NULL);
  if ((tab2[0] = malloc(sizeof(char) * 6)) == NULL)
    return (NULL);
  if ((tab2[1] = malloc(sizeof(char)* my_strlen(struc->next->instruction) + 1))
      == NULL)
    return (NULL);
  struc = struc->next;
  pars->path = "/bin/touch";
  tab2[0] = "touch";
  tab2[1] = struc->instruction;
  tab2[2] = NULL;
  return (tab2);
}

t_pars	*echo_write(t_pars *pars, char **env)
{
  int i;

  i = 0;
  while (pars->tab[i] != NULL)
    {
      if (i == 0)
	i++;
      if (my_strlen(pars->tab[i]) > 0)
	{
	  if (pars->tab[i][0] == '$')
	    write(1, find_in_env(env, pars->tab[i]),
	  my_strlen(find_in_env(env, pars->tab[i])));
	  else
	    write(1, pars->tab[i], my_strlen(pars->tab[i]));
	}
      if (pars->tab[i + 1] != NULL)
	write(1, " ", 1);
      i++;
    }
  write(1, "\n", 1);
  return (NULL);
}

t_pars	*echo_write_in_file(t_pars *pars, t_struct *struc)
{
  int	fd;
  int	i;

  i = 0;
  struc = struc->next;
  fd = open(struc->instruction, O_RDWR);
  struc = struc->prev;
  while (pars->tab[i] != NULL)
    {
      if (i == 0)
	i++;
      write(fd, pars->tab[i], my_strlen(pars->tab[i]));
      write(fd, " ", 1);
      i++;
    }
  close(fd);
  return (NULL);
}

t_pars	*my_echo_check(t_pars *pars, t_struct *struc, char **env, int pid)
{
  char	**tab2;

  if ((my_strncmp(pars->tab[0], "echo", 4) == 0) && (struc->operateur != 5))
    return (echo_write(pars, env));
  else if ((my_strncmp(pars->tab[0], "echo", 4) == 0)
    && (struc->operateur == 5))
    {
      tab2 = init_tab2(struc, pars);
      pid = fork();
      if (pid == 0)
	{
	  setpgrp();
	  execve(pars->path, tab2, env);
	  exit(0);
	}
      else
	wait(&pid);
      return (echo_write_in_file(pars, struc));
    }
  return (pars);
}
