/*
** my_str_islower.c for my_str_islower in /home/colin_h/rendu/Piscine_C_J06/ex_12
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct 20 14:17:49 2014 François Colin
** Last update Mon Oct 20 14:22:17 2014 François Colin
*/

int	my_str_islower(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 'a' || str[i] > 'z')
	return (0);
      i = i + 1;
    }
  return (1);
}
