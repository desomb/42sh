/*
** error_exe.c for error_exe in /home/quero_q/Dropbox/progra/42/lexer_42/source/main
**
** Made by quero_q
** Login   <quero_q@epitech.net>
**
** Started on  Fri May 22 14:46:10 2015 quero_q
** Last update Fri May 22 15:10:43 2015 Vincent Desombre
*/

#include <unistd.h>
#include <stdio.h>
#include "pars.h"
#include "error.h"
#include "my.h"

t_pars	*error_env(t_pars *t)
{
  my_putstr_error("error environ\n");
  return (t);
}

char	*error_cd(char *str)
{
  my_putstr_error("cd:  ");
  my_putstr_error(str);
  my_putstr_error(": No files or folders of this type\n");
  return (NULL);
}
