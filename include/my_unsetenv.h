/*
** my_unsetenv.h for my_unsetenv in /home/colin_h/rendu/On_going_project/PSU_2014_42sh
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Fri May 22 19:56:28 2015 François Colin
** Last update Fri May 22 19:57:18 2015 François Colin
*/

#ifndef _MY_UNSETENV_H_
#define _MY_UNSETENV_H_

char	**my_fill_env(char **tab, char **my_env, int var_nbr);
char    **my_actualize_env(char **my_env);
char	**my_unsetenv(char **my_env, char *option);

#endif /* _MY_UNSETENV_H_ */
