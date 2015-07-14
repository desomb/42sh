/*
** strcat_spe.c for s in /home/desomb_v/rendu/Projet/PSU/PSU_2014_42sh/source/parser
** 
** Made by Vincent Desombre
** Login   <desomb_v@epitech.net>
** 
** Started on  Fri May 22 19:58:17 2015 Vincent Desombre
** Last update Fri May 22 19:59:37 2015 Vincent Desombre
*/

#include <stdlib.h>
#include "my.h"

char    *my_strcatspe(char *s1, char *s2)
{
  char  *s3;
  int   cpt1;
  int   cpt2;

  cpt1 = 0;
  cpt2 = 0;
  if ((s3 = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2)+ 1))) == NULL)
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
