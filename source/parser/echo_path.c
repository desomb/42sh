/*
** echo_path.c for echo in /home/desomb_v/rendu/Projet/PSU/PSU_2014_42sh/source/parser
** 
** Made by Vincent Desombre
** Login   <desomb_v@epitech.net>
** 
** Started on  Sun May 24 21:55:53 2015 Vincent Desombre
** Last update Sun May 24 21:58:39 2015 Vincent Desombre
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char   *find_in_env(char **env, char *str)
{
  int   i;
  int   a;
  char  *str2;
  int   b;

  b = a = i = 0;
  str2 = NULL;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], str + 1, my_strlen(str) - 1) == 0 &&
	  my_strlen(env[i]) > my_strlen(str))
        {
          str2 = calloc((sizeof(char) * my_strlen(env[i]) + 1), 1);
          while (env[i][a] != '=')
            a++;
          while (env[i][++a])
            {
              str2[b++] = env[i][a];
            }
          str2[b] = 0;
          return (str2);
        }
      i++;
    }
  return ("");
}
