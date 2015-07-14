/*
** my_showmem.c for my_showmem in /home/colin_h/rendu/Piscine_C_J11/lib/my
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct 20 15:40:47 2014 François Colin
** Last update Sun Nov 16 22:26:36 2014 François Colin
*/

int	my_showmem(char *str, int size)
{
  int i;

  i = 0;
  while (str[i] == '\0')
    {
      i = i + 1;
      size = size - 1;
    }
  return (0);
}
