/*
** my_free.c for my_free in /home/quero_q/Dropbox/progra/42/PSU_2014_42sh/source/error
**
** Made by quero_q
** Login   <quero_q@epitech.net>
**
** Started on  Sat May 23 10:10:49 2015 quero_q
** Last update Sat May 23 23:48:31 2015 François Colin
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "my.h"

void	my_free_tab(char **tab)
{
  int 	i;

  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
}
