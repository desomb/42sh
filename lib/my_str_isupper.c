/*
** my_str_isupper.c for my_str_isupper in /home/colin_h/rendu/Piscine_C_J06
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct 20 14:23:22 2014 François Colin
** Last update Mon Oct 20 14:27:16 2014 François Colin
*/

int	my_str_isupper(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 'A' || str[i] > 'Z')
	return (0);
      i = i + 1;
    }
  return (1);
}
