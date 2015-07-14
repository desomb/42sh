/*
** pars_check.c for 42sh in /home/colin_h/rendu/On_going_project/lexer_42
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Tue May 19 22:43:50 2015 François Colin
** Last update Tue May 19 22:46:54 2015 François Colin
*/

#ifndef _PARS_CHECK_H_
#define _PARS_CHECK_H_

int     check_char(char *str, char c, int max);
char    *check_param(char *str, char c);
char    *check_sep(char *str);
char    *pars_check(char *str);
void    clear_buff(char *s);

#endif /* _PARS_CHECK_H_ */
