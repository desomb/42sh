/*
** get_next_line.c for get_next_line in /home/colin_h/test/TPS/TPget_next_line
**
** Made by François Colin
** Login   <colin_h@epitech.net>
**
** Started on  Fri Jan 16 09:58:37 2015 François Colin
** Last update Sun May 24 17:39:35 2015 François Colin
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "get_next_line.h"

char    *my_spe_strcat(char *s1, char *s2)
{
  char	*s3;
  int	cpt1;
  int	cpt2;

  cpt1 = my_strlen(s1);
  cpt2 = 0;
  if ((s3 = calloc((sizeof(char) * (cpt1 + my_strlen(s2) + 1)), 1)) == NULL)
    return (NULL);
  if (s1 != NULL)
    {
      s3 = my_strcpy(s3, s1);
      free(s1);
    }
  while (s2[cpt2] != '\0' && s2[cpt2] != '\n')
    s3[cpt1++] = s2[cpt2++];
  s3[cpt1] = '\0';
  return (s3);
}

char	*check_buff(char *str, char buffer[1][BUFFER_SIZE], int i, int *j)
{
  if (buffer[0][i] == '\n' || buffer[0][i] == '\0')
    buffer[0][i++] = '\0';
  str = my_spe_strcat(str, &buffer[0][i]);
  i = 0;
  while (*buffer[i] != '\n' && i < BUFFER_SIZE)
    i++;
  *buffer[i] = '\0';
  *j = i;
  return (str);
}

char    *get_next_line(int fd)
{
  char *str;
  static char buffer[BUFFER_SIZE];
  static int i;
  int e;

  str = NULL;
  if (i < BUFFER_SIZE)
    str = check_buff(str, &buffer, i, &i);
  else
    i = BUFFER_SIZE;
  while (i == BUFFER_SIZE && (e = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
      buffer[e] = '\0';
      str = my_spe_strcat(str, buffer);
      i = 0;
      while (buffer[i] != '\0' && buffer[i] != '\n')
	buffer[i++] = '\0';
      buffer[i] = '\0';
    }
  if (e == 0 && (str == NULL || str[0] == '\0'))
    return (NULL);
  return (str);
}
