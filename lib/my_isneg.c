/*
** my_isnegtest.c for exo4 in /home/colin_h/test/Exo04
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Wed Oct  1 10:47:26 2014 François Colin
** Last update Sun Nov 16 21:23:48 2014 François Colin
*/

#include "my.h"

int	my_isneg(int n)
{
  if (n >= 0)
    {
      my_putchar('P');
    }
  else
    {
      my_putchar('N');
    }
  return (0);
}
