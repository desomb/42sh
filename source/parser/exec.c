/*
** exec.c for 42sh in /home/colin_h/rendu/On_going_project/PSU_2014_42sh
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Sun May 24 22:54:00 2015 François Colin
** Last update Sun May 24 22:54:02 2015 François Colin
*/

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <my.h>
#include <errno.h>
#include <stdlib.h>
#include "my.h"
#include "list.h"
#include "pars.h"

int	execution(t_pars *pars, char **env)
{
  int	ret;
  int	acc;

  acc = access(pars->path, X_OK);
  if (acc < 0)
    return (acc);
  if ((ret = execve(pars->path, pars->tab, env)) == -1)
  {
  	my_putstr(strerror(errno));
  	exit(-1);
  }
  if (ret < 0)
    return (-1);
  return (0);
}
