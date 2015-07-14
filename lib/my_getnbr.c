/*
** my_getnbr.c for my_getnbr in /home/colin_h/rendu/Piscine_C_J04
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Wed Oct  8 10:18:41 2014 François Colin
** Last update Tue Apr 21 15:01:10 2015 François Colin
*/

int	my_getnbr(char *str)
{
  int i;
  int compteur;
  int nb;
  int res;
  int a;

  compteur = 1;
  i = 0;
  res = 0;
  while (str[i] != 0 && (str[i] < '0' || str[i] > '9'))
    i = i + 1;
  nb = i;
  while (str[i] != 0 && str[i] >= '0' && str[i] <= '9')
    i = i + 1;
  i--;
  while (i >= nb)
    {
      a = str[i] - '0';
      res = res + (a * compteur);
      compteur = compteur * 10;
      i = i - 1;
    }
  if (nb > 0 && str[nb - 1] == '-')
    res = -res;
  return (res);
}
