/*
** my_strcmp.c for my_strcmp in /home/colin_h/rendu/Piscine_C_J06/ex_05
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Wed Oct  8 18:37:54 2014 François Colin
** Last update Thu May 21 10:50:30 2015 François Colin
*/

#include "my.h"

int    my_strcmp(char *s1, char *s2)
{
  int i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    i++;
  if (s1[i] == '\0' && s2[i] == '\0')
    return (0);
  return (1);
}
