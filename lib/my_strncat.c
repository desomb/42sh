/*
** my_strncat.c for my_strncat in /home/colin_h/rendu/Piscine_C_J11/lib/my
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct 20 15:44:48 2014 François Colin
** Last update Sun Nov 16 22:31:15 2014 François Colin
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int i;

  i = 0;
  while (dest[i] == '\0' && src[i] == '\0')
    {
      i = i + 1;
      nb = nb - 1;
    }
  return (0);
}
