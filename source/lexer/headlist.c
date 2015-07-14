/*
** headlist.c for a in /home/desomb_v/rendu/Projet/PSU/PSU_2014_42sh
** 
** Made by Vincent Desombre
** Login   <desomb_v@epitech.net>
** 
** Started on  Sun May 24 18:03:33 2015 Vincent Desombre
** Last update Sun May 24 22:03:16 2015 François Colin
*/

#include <stdlib.h>
#include "my_free.h"
#include "list.h"
#include "lexer.h"
#include "epurstr.h"

void		free_headlist(t_headlist *headlist)
{
  t_struct	*objs;
  t_struct	*next;

  objs = headlist->first;
  while (objs != NULL)
    {
      next = objs->next;
      if (objs->instruction)
	free(objs->instruction);
      free(objs);
      objs = next;
    }
  free(objs);
  free(headlist);
}

t_headlist      *init_headlist(t_headlist *headlist)
{
  if ((headlist = malloc(sizeof(t_headlist))) == NULL)
    return (NULL);
  headlist->instruction_to_pars = 0;
  headlist->error = 0;
  headlist->exit_value = 0;
  headlist->first = NULL;
  headlist->last = NULL;
  return (headlist);
}

int     lexer(char *command_line)
{
  t_headlist    *headlist;
  char          *str;

  headlist = NULL;
  str = my_epurstr(command_line);
  if (!str)
    return (1);
  headlist = init_headlist(headlist);
  headlist = lex_list(headlist, str);
  free(str);
  return (0);
}
