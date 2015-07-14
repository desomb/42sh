/*
** error.h for 42sh in /home/colin_h/rendu/On_going_project/lexer_42/include
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Tue May 19 19:19:34 2015 quero_q
** Last update Sat May 23 19:18:05 2015 Vincent Desombre
*/

#ifndef _ERROR_H_
#define _ERROR_H_

#include "pars.h"

void	my_putst_error(char *str);
void	my_putstr_error(char *str);
char    *error_check(char c);
char 	*error_malloc();
char	*error_read(char *);
t_pars 	*error_execve(char *str, t_pars *pars);
char    *error_cd(char *str);

#endif /* _ERROR_H_ */
