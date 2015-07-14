/*
** my_strcat.c for my_strcat in /home/colin_h/rendu/Piscine_C_J11/lib/my
**
** Made by François Colin
** Login   <colin_h@epitech.net>
**
** Started on  Mon Oct 20 15:41:34 2014 François Colin
** Last update Sun May 24 22:59:31 2015 Vincent Desombre
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *s1, char *s2)
{
  char  *s3;
  int   cpt1;
  int   cpt2;

  cpt1 = 0;
  cpt2 = 0;
  if ((s3 = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1)))
      == NULL)
    return (NULL);
  if (s1 != NULL)
    {
      s3 = my_strcpy(s3, s1);
      cpt1 = my_strlen(s1);
    }
  while (s2[cpt2] != '\0')
    s3[cpt1++] = s2[cpt2++];
  s3[cpt1] = '\0';
  return (s3);
}
