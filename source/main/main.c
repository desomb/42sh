/*
** main.c for 42sh in /home/colin_h/rendu/On_going_project/PSU_2014_42sh
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Sun May 24 22:53:23 2015 François Colin
** Last update Sun May 24 22:53:23 2015 François Colin
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "my_free.h"
#include "my_setenv.h"
#include "my_getenv.h"
#include "error.h"
#include "prompt.h"
#include "my_unsetenv.h"
#include "my_str_to_wordtab.h"
#include "get_next_line.h"
#include "lexer.h"
#include "headlist.h"
#include "epurstr.h"
#include "pars.h"
#include "pars_check.h"

void	free_pars(t_pars *pars)
{
  if (pars->path)
    free(pars->path);
  if (pars->tab)
    my_free_tab(pars->tab);
  if (pars)
    free(pars);
}

t_headlist	*go_to_pars(t_headlist *headlist, char *buff, char ***env)
{
  t_struct	*cmd;
  t_pars	*pars;

  pars = NULL;
  pars = my_parstruc_init(pars);
  headlist = lex_list(headlist, buff);
  cmd = headlist->first;
   if ((cmd->operateur != 4 &&
	cmd->operateur != 5 && cmd->operateur != 6 &&
	cmd->operateur != 7) && cmd->instruction == NULL)
     my_putstr("syntax error\n");
   else
     while (cmd != NULL)
       {
	 if (cmd->instruction != NULL)
	   pars = my_pars(cmd, env, pars);
	 if (pars->error == -10)
	   {
	     headlist->exit_value = pars->exit_value;
	     headlist->error = -10;
	   }
	 cmd = cmd->next;
       }
   return (headlist);
}

void	catch_ctrl_c()
{
}

int	main()
{
  extern char	**environ;
  t_headlist	*headlist;
  char		*buff;
  char		**env;

  prompt(environ);
  env = my_getenv(environ);
  signal(SIGINT, catch_ctrl_c);
  while ((buff = get_next_line(0)) != NULL)
    {
      signal(SIGINT, catch_ctrl_c);
      if (check_handle_exit(buff) == 0)
	return (handle_exit(buff, env));
      else if (pars_check(buff) != NULL &&
	       check_builtins(buff, &env) == 1)
	{
	  headlist = go_to_pars(headlist, buff, &env);
	  if (headlist->error == -10)
	    return (headlist->exit_value);
	  free_headlist(headlist);
	}
      prompt(env);
      free(buff);
    }
  return (0);
}
