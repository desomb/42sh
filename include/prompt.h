/*
** prompt.h for 42sh in /home/colin_h/rendu/On_going_project/PSU_2014_42sh
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Sun May 24 21:09:14 2015 François Colin
** Last update Sun May 24 22:10:12 2015 François Colin
*/

#ifndef _PROMPT_H_
#define _PROMPT_H_

void    prompt(char **env);
int     find_home(char **env);
int     my_exit(char **env, char *str);
int     my_exit_nbr_test(char *buff);
int     my_exit_nbr(char *buff);
int     check_handle_exit(char *buff);
int     handle_exit(char *buff, char **env);

#endif /* _PROMPT_H_ */
