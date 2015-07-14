/*
** lexer.h for 42sh in /home/colin_h/rendu/On_going_project/lexer_42
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Tue May 19 19:40:51 2015 François Colin
** Last update Tue May 19 19:45:22 2015 François Colin
*/

#ifndef _LEXER_H_
#define _LEXER_H_

#include "list.h"

char		is_delimiter(char *str, int *i);
t_headlist      *lex_list(t_headlist *headlist, char *str);
char		*get_instruction(t_struct *objs, char *str, int save, int *save_i);
char		is_background(char *str, int i);

#endif /*_LEXER_H_ */
