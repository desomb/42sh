/*
** my_strncmp.c for my_strncmp in /home/colin_h/rendu/Piscine_C_J11/lib/my
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct 20 11:30:11 2014 François Colin
** Last update Fri May 22 18:57:24 2015 Vincent Desombre
*/

int     my_strncmp(char *str, char *str2, int i)
{
  int   j;

  j = 0;
  if (my_strlen(str) < i)
    return (1);
  while (j < i)
    {
      if (str[j] != str2[j])
        return (1);
      j++;
    }
  return (0);
}
