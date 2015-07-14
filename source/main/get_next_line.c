/*
** get_next_line.c for gnl in /home/desomb_v/rendu/Projet/PSU/42/lexer_42/source
** 
** Made by Vincent Desombre
** Login   <desomb_v@epitech.net>
** 
** Started on  Tue May 19 16:04:48 2015 Vincent Desombre
** Last update Tue May 19 16:04:49 2015 Vincent Desombre
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

int	len(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (i);
  while (str[i] != '\0')
    i++;
  return (i);
}

char     *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  if (src == NULL)
    return (dest);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}

char	*strct(char *dest, char *src, int *tmp)
{
  int	a;
  char	*mal;

  if ((mal = malloc((len(dest) + len(src)) * sizeof(char) + 1)) == NULL)
    return (NULL);
  mal = my_strcpy(mal, dest);
  a = len(dest);
  while (src[*tmp] != '\0' && src[*tmp] != '\n')
    {
      mal[a] = src[*tmp];
      (*tmp)++;
      a++;
    }
  mal[a] = '\0';
  return (mal);
}

char	*get_next_line(const int fd)
{
  static char	buffer[BUFFER_SIZE + 1];
  static int	tmp = 0;
  int		n;
  char		*line;

  line = NULL;
  if (fd < 0)
    return (NULL);
  if (buffer[tmp++] == '\n')
    {
      line = strct(line, buffer, &tmp);
      if (buffer[tmp] == '\n')
	return (line);
    }
  while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
      buffer[n] = '\0';
      tmp = 0;
      line = strct(line, buffer, &tmp);
      if (buffer[tmp] == '\n')
	return (line);
    }
  if (line != NULL && line[0] == 0)
      return (NULL);
  return (line);
}
