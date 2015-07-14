/*
** parsnomre.c for pars in /home/desomb_v/rendu/Projet/PSU/PSU_2014_42sh/source/parser
**
** Made by Vincent Desombre
** Login   <desomb_v@epitech.net>
**
** Started on  Sun May 24 19:39:14 2015 Vincent Desombre
** Last update Sun May 24 22:50:50 2015 François Colin
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "path.h"
#include "pars.h"
#include "list.h"

t_pars          *pars_norme(t_struct *struc, t_pars *pars, char ***env)
{
  pars->error = 0;
  if ((execution(pars, *env)) == -1)
    return (error_execve(struc->instruction, pars));
  exit(0);
  return (pars);
}
