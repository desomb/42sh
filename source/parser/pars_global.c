/*
** pars_global.c for pars in /home/desomb_v/rendu/Projet/PSU/42/test/source/parser
** 
** Made by Vincent Desombre
** Login   <desomb_v@epitech.net>
** 
** Started on  Thu May 21 22:06:45 2015 Vincent Desombre
** Last update Thu May 21 22:09:29 2015 Vincent Desombre
*/

#include "path.h"
#include "pars.h"
#include "list.h"
#include "error.h"
#include "my.h"

t_pars	*my_global_pars_path(t_pars *pars)
{
  int	i;

  i = 0;
  while (pars->path[i])
    {
      if (pars->path[i] == ' ')
	break;
      i++;
    }
  pars->path[i] = 0;
  return (pars);
}
