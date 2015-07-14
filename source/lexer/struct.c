/*
** struct.c for 42 in /home/colin_h/rendu/On_going_project/lexer_42/source
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Thu Apr 23 16:22:09 2015 François Colin
** Last update Fri May 22 15:20:13 2015 François Colin
*/

#include <stdlib.h>
#include "list.h"
#include "my.h"

t_struct	*add_struct(t_headlist *headlist, int *statut)
{
  t_struct	*objs;

  if ((objs = malloc(sizeof(t_struct))) == NULL)
    return (NULL);
  *statut = 1;
  objs->operateur = '\0';
  objs->background = '\0';
  objs->instruction = NULL;
  objs->next = NULL;
  objs->prev = headlist->last;
  headlist->last->next = objs;
  headlist->last = objs;
  headlist->instruction_to_pars++;
  return (objs);
}

t_struct	*init_struct(t_headlist *headlist, int *statut)
{
  t_struct	*objs;

  if ((objs = malloc(sizeof(t_struct))) == NULL)
    return (NULL);
  *statut = 1;
  objs->operateur = '\0';
  objs->background = '\0';
  objs->instruction = NULL;
  objs->next = NULL;
  objs->prev = NULL;
  headlist->first = objs;
  headlist->last = objs;
  headlist->instruction_to_pars++;
  return (objs);
}

void	my_aff_struct_info(t_struct *objs)
{
  my_putstr("operateur: ");
  my_put_nbr(objs->operateur);
  my_putchar('\n');
  my_putstr("instruction: ");
  my_putstr(objs->instruction);
  my_putchar('\n');
  my_putstr("background: ");
  my_put_nbr(objs->background);
  my_putchar('\n');
  my_putchar('\n');
}

void	my_aff_list_info(t_headlist *headlist)
{
  t_struct	*objs;
  int	i;

  i = headlist->instruction_to_pars;
  objs = headlist->first;
  while (i > 0)
    {
      my_aff_struct_info(objs);
      objs = objs->next;
      i--;
    }
}
