/*
** my_sort_int_tab.c for my_sort_int_tab in /home/colin_h/rendu/Piscine_C_J04
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Fri Oct 17 16:11:30 2014 François Colin
** Last update Sun Nov 16 21:28:32 2014 François Colin
*/

#include <stdlib.h>
#include "my.h"

void	my_sort_int_tab(int *tab, int size)
{
  int i;
  int j;
  int k;

  i = 0;
  j = 0;
  k = 0;
  while (k < size)
    {
      while (j < size)
	{
	  if (tab[j] == i)
	    {
	      my_swap(&tab[j], &tab[k]);
	      k = k + 1;
	    }
	  j = j + 1;
	}
      j = k;
      i = i + 1;
    }
}
