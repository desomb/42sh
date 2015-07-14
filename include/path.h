/*
** path.h for 42sh in /home/colin_h/rendu/On_going_project/lexer_42
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Thu May 21 15:20:08 2015 François Colin
** Last update Thu May 21 15:21:50 2015 François Colin
*/

#ifndef _PATH_H_
#define _PATH_H_

#include "pars.h"

int		my_global_path(t_struct *struc);
t_pars          *pars_path(t_pars *pars, char **env, int a);
t_pars          *my_path_access(t_pars *pars, char **env, int a);

#endif /* _PATH_H_ */
