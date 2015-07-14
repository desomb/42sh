/*
** my_swapt.c for my_swap in /home/colin_h/test/Day04/ex1
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Thu Oct  2 11:26:35 2014 François Colin
** Last update Fri Oct  3 21:37:59 2014 François Colin
*/

void my_swap(int *a, int *b)
{
  int c;

  c = *a;
  *a = *b;
  *b = c;
}
