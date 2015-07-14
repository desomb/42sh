/*
** test.c for test in /home/colin_h/test/Exo07
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Wed Oct  1 20:22:30 2014 François Colin
** Last update Sun Nov 16 21:24:26 2014 François Colin
*/

#include "my.h"

int my_put_nbr(int nb)
{
  int pow;
  int div;
  int i;

  i = 0;
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  div = nb;
  pow = 1;
  while (nb / pow >= 10)
    pow = pow * 10;
  my_putchar(48 + div / pow);
  while (pow > 1)
    {
      i = i + 1;
      div = nb % pow;
      pow = pow / 10;
      div = div / pow;
      my_putchar(48 + div);
      nb = nb % pow;
    }
  return (i + 1);
}
