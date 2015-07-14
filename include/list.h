/*
** list.h for 42 in /home/colin_h/rendu/On_going_project/lexer_42/include
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Thu Apr 23 15:42:05 2015 François Colin
** Last update Sun May 24 17:30:40 2015 Vincent Desombre
*/

#ifndef _LIST_H_
#define _LIST_H_

typedef struct s_struct
{
  char			operateur;
  char			*instruction;
  char			background;
  struct s_struct	*next;
  struct s_struct	*prev;
} t_struct;

typedef struct s_headlist
{
  int		instruction_to_pars;
  t_struct	*first;
  t_struct	*last;
  int		exit_value;
  int		error;
} t_headlist;

#endif /* _LIST_H_ */
