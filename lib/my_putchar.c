/*
** my_putchar.c for libmy in /home/colin_h/rendu/Piscine_C_J11/lib/my
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon Oct 20 09:21:54 2014 François Colin
** Last update Sun Nov 16 21:18:40 2014 François Colin
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
