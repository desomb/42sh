/*
** prompt.c for 42sh in /home/colin_h/rendu/On_going_project/PSU_2014_42sh
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Sun May 24 21:07:21 2015 François Colin
** Last update Sun May 24 21:13:16 2015 François Colin
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int     find_home(char **env)
{
  int i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "HOME=", 5) == 0 && my_strlen(env[i]) > 5)
        return (my_strlen(env[i]) - 5);
      i++;
    }
  return (0);
}

void    prompt(char **env)
{
  int i;
  int home;

  i = 0;
  home = 0;
  write(1, "$", 1);
  if (env != NULL)
    {
      while (env[i] != NULL)
        {
          if (my_strncmp(env[i], "USER=", 5) == 0 && my_strlen(env[i]) > 5)
            write(1, env[i] + 5, my_strlen(env[i]) - 5);
          i++;
        }
      write(1, ":~", 2);
      i = -1;
      home = find_home(env);
      while (env[++i] != NULL)
        {
          if (my_strncmp(env[i], "PWD=", 4) == 0
	      && my_strlen(env[i]) > home + 4)
	    write(1, env[i] + home + 4, my_strlen(env[i]) - home - 4);
        }
    }
  write(1, "> ", 2);
}
