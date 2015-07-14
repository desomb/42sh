/*
** my_setenv.h for my_setenv in /home/colin_h/rendu/On_going_project/PSU_2014_42sh
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Fri May 22 19:55:12 2015 François Colin
** Last update Fri May 22 19:55:49 2015 François Colin
*/

#ifndef _MY_SETENV_H_
#define _MY_SETENV_H_

int     my_spe_strlen(char *option);
char    **my_change_var(char **my_env, int i, char *option, int len);
char    **create_new_var(char **my_env, int i, char *option, int len);
char    **my_setenv(char **my_env, char *option);

#endif /* _MY_SETENV_H_ */
