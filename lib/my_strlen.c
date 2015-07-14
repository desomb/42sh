/*
** my_strlen.c for my_strlen in /home/colin_h/test/Day04/ex3
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Thu Oct  2 16:58:25 2014 François Colin
** Last update Fri Jan 16 13:32:22 2015 François Colin
*/

int	my_strlen(char *str)
{
  int a;

  a = 0;
  if (str)
    {
      while (str[a] != '\0')
	a = a + 1;
    }
  return (a);
}
