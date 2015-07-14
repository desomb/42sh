/*
** headlist.h for 42sh in /home/colin_h/rendu/On_going_project/lexer_42
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Tue May 19 19:37:12 2015 François Colin
** Last update Sun May 24 22:02:56 2015 François Colin
*/

#ifndef _HEADLIST_H_
#define _HEADLIST_H_

#include "list.h"

int		lexer(char *command_line);
t_headlist	*init_headlist(t_headlist *headlist);
void		free_headlist(t_headlist *headlist);

#endif /* _HEADLIST_H_ */
