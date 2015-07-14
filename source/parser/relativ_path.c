/*
** relativ_path.c for relativ in /home/desomb_v/rendu/Projet/PSU/PSU_2014_42sh/source/parser
** 
** Made by Vincent Desombre
** Login   <desomb_v@epitech.net>
** 
** Started on  Sat May 23 19:07:08 2015 Vincent Desombre
** Last update Sat May 23 19:07:38 2015 Vincent Desombre
*/

#include "list.h"
#include "pars.h"

t_pars          *my_relativ_path(t_struct *struc, t_pars *pars)
{
  int   i;
  int   a;

  a = 0;
  i = 2;
  while (struc->instruction[i])
    {
      pars->path[a] = struc->instruction[i];
      i++;
      a++;
    }
  pars->path[a] = '\0';
  return (pars);
}
