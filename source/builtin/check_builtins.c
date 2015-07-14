/*
** check_builtins.c for 42sh in /home/colin_h/rendu/On_going_project/PSU_2014_42sh
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Sun May 24 21:58:31 2015 François Colin
** Last update Sun May 24 21:59:20 2015 François Colin
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "my_setenv.h"
#include "my_getenv.h"
#include "my_unsetenv.h"

int     check_builtins(char *str, char ***env)
{
  if (my_strncmp(str, "setenv ", 7) == 0)
    *env = my_setenv(*env, &str[7]);
  else if (my_strncmp(str, "unsetenv ", 9) == 0)
    *env = my_unsetenv(*env, &str[9]);
  else if (my_strcmp(str, "env") == 0)
    aff_my_env(*env);
  else
    return (1);
  return (0);
}

