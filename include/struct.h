/*
** struct.h for 42sh in /home/colin_h/rendu/On_going_project/lexer_42
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Tue May 19 19:48:09 2015 François Colin
** Last update Tue May 19 19:49:56 2015 François Colin
*/

#ifndef _STRUCT_H_
#define _STRUCT_H_

#include "list.h"

void		my_aff_list_info(t_headlist *headlist);
void		my_aff_struct_info(t_struct *objs);
t_struct        *init_struct(t_headlist *headlist, int *statut);
t_struct        *del_struct(t_headlist *headlist, t_struct *obj);
t_struct        *add_struct(t_headlist *headlist, int *statut);

#endif /* _STRUCT_H8 */
