/*
** my_strlcat.c for my_strlcat in /home/colin_h/rendu/Piscine_C_J11/lib/my
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct 20 15:45:32 2014 François Colin
** Last update Sun Nov 16 22:34:04 2014 François Colin
*/

int	my_strlcat(char *dest, char *src, int size)
{
  int i;

  i = 0;
  while (dest[i] != '\0' && src[i] != '\0')
    {
      i = i + 1;
      size = size - 1;
    }
  return (0);
}
