/*
** pars.h for pars in /home/desomb_v/rendu/Projet/PSU/PSU_2014_42sh
** 
** Made by Vincent Desombre
** Login   <desomb_v@epitech.net>
** 
** Started on  Tue May  5 16:50:10 2015 Vincent Desombre
** Last update Sun May 24 22:19:07 2015 gautier vaillant
*/

#ifndef _PARS_H_
#define _PARS_H_

#include "list.h"

typedef struct s_pars
{
  int	error;
  int	pipe;
  int	last_op;
  int	exit_value;
  char	*save;
  char	*path;
  char	**tab;
} t_pars;

t_pars          *pars_path(t_pars *pars, char **env, int a);
t_pars          *my_path_access(t_pars *pars, char **env, int a);
int		my_global_path(t_struct *struc);
t_pars		*my_global_remp(t_pars *pars, t_struct *struc);
t_pars          *my_path_remp(t_struct *struc, char **env, t_pars *pars, int i);
t_pars          *my_parstruc_init(t_pars *pars);
t_pars          *my_pars(t_struct *struc, char ***env, t_pars *pars);
t_pars		*my_global_pars_path(t_pars *pars);
t_pars		*my_echo_check(t_pars *pars, t_struct *struc, char **env, int pid);
int		execution(t_pars *pars, char **env);
t_pars          *my_relativ_path(t_struct *struc, t_pars *pars);
t_pars          *pars_norme(t_struct *struc, t_pars *pars, char ***env);
char		*find_in_env(char **env, char *str);
t_pars		*error_execve(char *str, t_pars *pars);

#endif
