/*
** error.c for 42sh in /home/colin_h/rendu/On_going_project/lexer_42/source/main
**
** Made by François Colin
** Login   <colin_h@epitech.net>
**
** Started on  Thu May 21 16:07:58 2015 quero_q
** Last update Sun May 24 17:46:48 2015 François Colin
*/

#include <unistd.h>
#include <stdio.h>
#include "my_str_to_wordtab.h"
#include "pars.h"
#include "my.h"

void	my_putstr_error(char *str)
{
  write(2, str, my_strlen(str));
}

char 	*error_malloc()
{
  my_putstr_error("malloc error");
  my_putstr_error("\n");
  return (NULL);
}

char	*error_check(char c)
{
  my_putstr_error("shell: syntax error ");
  my_putstr_error("near unexpected token ' ");
  write(2, &c, 1);
  my_putstr_error(" '\n");
  return (NULL);
}

char	*error_read(char *str)
{
  my_putstr_error("read error");
  my_putstr_error(str);
  my_putstr_error("\n");
  return (NULL);
}

t_pars  *error_execve(char *str, t_pars *pars)
{
  char	**tab;

  tab = my_str_to_wordtab(str);
  pars->error = 1;
  my_putstr_error(str);
  my_putstr_error(" : command not found");
  my_putstr_error("\n");
  if (my_strncmp(str, "exit", 4) == 0)
    {
      if (tab[1] != NULL)
	pars->exit_value = my_getnbr(tab[1]);
      pars->error = -10;
    }
  return (pars);
}
