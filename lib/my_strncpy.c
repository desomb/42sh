/*
** my_strncpy.c for my_strncpy in /home/colin_h/test/Day6
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct  6 11:19:16 2014 François Colin
** Last update Mon Oct  6 21:49:08 2014 François Colin
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int i;

  i = 0;
  while (i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
