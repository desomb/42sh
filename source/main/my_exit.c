/*
** my_exit.c for 42sh in /home/colin_h/rendu/On_going_project/PSU_2014_42sh
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Sun May 24 21:10:53 2015 François Colin
** Last update Sun May 24 22:10:14 2015 François Colin
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "my_free.h"
#include "error.h"
#include "my_str_to_wordtab.h"

int     my_exit(char **env, char *str)
{
  free(str);
  my_free_tab(env);
  my_putstr("exit\n");
  return (0);
}

int     my_exit_nbr_test(char *buff)
{
  int fin;
  char **dtab;

  dtab = NULL;
  fin = 0;
  if ((dtab = my_str_to_wordtab(buff)) == NULL)
    return (0);
  if (dtab[1] != NULL)
    {
      if (dtab[2] == NULL && my_getnbr(dtab[1]) != 0)
        {
          fin = my_getnbr(dtab[1]);
        }
      else if (dtab[2] != NULL ||
	       (my_getnbr(dtab[1]) == 0 && dtab[1][0] != '0'))
        {
          my_putstr_error("exit: Expression Syntax.\n");
          return (0);
        }
    }
  return (fin);
}

int     my_exit_nbr(char *buff)
{
  int fin;
  char **dtab;

  dtab = NULL;
  fin = 0;
  if ((dtab = my_str_to_wordtab(buff)) == NULL)
    return (0);
  if (dtab[1] != NULL)
    {
      if (dtab[2] == NULL && my_getnbr(dtab[1]) != 0)
        {
          fin = my_getnbr(dtab[1]);
        }
      else if (my_getnbr(dtab[1]) == 0 && dtab[1][0] != '0')
        {
          return (0);
        }
    }
  my_putstr("exit\n");
  return (fin);
}

int     handle_exit(char *buff, char **env)
{
  if (my_strcmp(buff, "exit") == 0)
    return (my_exit(env, buff));
  if (my_strncmp(buff, "exit ", 5) == 0)
    if (my_exit_nbr_test(buff) != 0)
      return (my_exit_nbr(buff));
  return (0);
}

int     check_handle_exit(char *buff)
{
  if (my_strcmp(buff, "exit") == 0)
    return (0);
  if (my_strncmp(buff, "exit ", 5) == 0)
    {
      if (my_exit_nbr_test(buff) != 0)
        return (0);
    }
  return (1);
}
