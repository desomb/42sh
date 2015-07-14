/*
** my_power_rec.c for my_power_rec.c in /home/colin_h/rendu/Piscine_C_J05
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Sun Oct  5 10:34:27 2014 François Colin
** Last update Sun Nov 16 21:30:06 2014 François Colin
*/

#include "my.h"

int	my_power_rec(int nb, int power)
{
  if (power + 1 > 1)
    {
      return (nb * (my_power_rec(nb, power - 1)));
      if ((nb * (my_power_rec(nb, power - 1))) > 2147483647)
	return (0);
    }
  else if ( power < 0)
    return (0);
  else if ( power == 0)
    return (1);
  return (0);
}
