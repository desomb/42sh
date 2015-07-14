/*
** pars.c for pars in /home/desomb_v/rendu/Projet/PSU/PSU_2014_42sh
**
** Made by Vincent Desombre
** Login   <desomb_v@epitech.net>
**
** Started on  Tue May  5 16:41:55 2015 Vincent Desombre
** Last update Thu May 28 17:15:13 2015 François Colin
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my_cd.h"
#include "my_str_to_wordtab.h"
#include "path.h"
#include "pars.h"
#include "list.h"
#include "error.h"
#include "error_exe.h"
#include "my.h"

t_pars	*my_global_remp(t_pars *pars, t_struct *struc)
{
  int	i;
  int	a;

  a = 1;
  i = 0;
  while (struc->instruction[i])
    {
      pars->path[i] = struc->instruction[i];
      i++;
    }
  pars->path[i] = '\0';
  i = 0;
  while (pars->tab[0][a] != '/')
    a++;
  a++;
  while (pars->tab[0][a])
    {
      pars->tab[0][i] = pars->tab[0][a];
      i++;
      a++;
    }
  return (my_global_pars_path(pars));
}

t_pars		*my_parstruc_init(t_pars *pars)
{
  if ((pars = malloc(sizeof(t_pars))) == NULL)
    return (NULL);
  pars->pipe = 0;
  pars->error = 0;
  pars->last_op = 0;
  pars->path = NULL;
  pars->exit_value = 0;
  return (pars);
}

int     my_pars_no_error(t_pars *pars, t_struct *struc)
{
  if (pars->last_op == 0 && struc->operateur == 3)
    return (0);
  if (pars->last_op == 0 && struc->operateur != 3)
    return (1);
  if (pars->last_op == 1)
    return (1);
  if (pars->last_op == 2)
    return (0);
  if (pars->last_op == 3)
    return (0);
  if (pars->last_op == 4)
    return (0);
  if (pars->last_op == 5)
    return (0);
  if (pars->last_op == 6)
    return (0);
  if (pars->last_op == 7)
    return (0);
  if (pars->last_op == 8)
    return (1);
  return (-1);
}

int             my_pars_check(t_pars *pars, t_struct *struc)
{
  if (pars->error == 1)
    {
      if (pars->last_op == 0)
	return (1);
      if (pars->last_op == 1)
	return (0);
      if (pars->last_op == 2)
	return (1);
      if (pars->last_op == 3)
	return (0);
      if (pars->last_op == 4)
	return (0);
      if (pars->last_op == 5)
	return (1);
      if (pars->last_op == 6)
	return (1);
      if (pars->last_op == 8)
	return (1);
    }
  return (my_pars_no_error(pars, struc));
}

t_pars		*my_pars(t_struct *struc, char ***env, t_pars *pars)
{
  int	pid;

  if (*env == NULL)
    return (error_env(pars));
  if ((my_pars_check(pars, struc)) == 1)
    {
      pars->last_op = struc->operateur;
      pars->tab = my_str_to_wordtab(struc->instruction);
      if ((my_echo_check(pars, struc, *env, pid)) == NULL)
	return (pars);
      pars = my_echo_check(pars, struc, *env, pid);
      pars = my_path_remp(struc, *env, pars, 0);
      if (my_strcmp(pars->tab[0], "cd") == 0)
	env = my_cd(pars->tab, env);
      else if (pars->path != NULL)
	{
	  pid = fork();
	  if (pid == 0)
	    pars = pars_norme(struc, pars, env);
	  wait(&pid);
	}
      else
	pars = error_execve(struc->instruction, pars);
    }
  return (pars);
}
