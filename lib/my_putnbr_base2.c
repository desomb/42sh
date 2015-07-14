/*
** my_putnbr_base.c for my_putnbr_base in /home/colin_h/rendu/PSU_2014_my_printf
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Thu Nov 13 08:52:46 2014 François Colin
** Last update Sun Nov 16 16:22:33 2014 François Colin
*/

int	my_putnbr_base2(void *adresses, char *base)
{
  unsigned long nb;
  unsigned long pow;
  unsigned long div;
  int i;

  i = 0;
  nb = (unsigned long)adresses;
  div = nb;
  pow = 1;
  while (nb / pow >= my_strlen(base))
    pow = pow * base_len;
  my_putchar(48 + div/pow);
  while (pow > 1)
    {
      i = i + 1;
      div = nb % pow;
      pow = pow / my_strlen(base);
      div = div / pow;
      my_putchar(base[div]);
    }
  return (i + 1);
}
