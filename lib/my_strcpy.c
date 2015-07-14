/*
** my_strcpy.c for my_strcpy.c in /home/colin_h/test/Day6
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct  6 09:10:43 2014 François Colin
** Last update Sun Feb  1 15:21:14 2015 François Colin
*/

char	*my_strcpy(char *dest, char *src)
{
  int	 i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
