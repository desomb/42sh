/*
** lexer.c for 42sh in /home/colin_h/rendu/On_going_project/lexer_42/source
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Mon May 11 11:53:29 2015 François Colin
** Last update Sun May 24 21:45:49 2015 François Colin
*/

#include <stdlib.h>
#include "list.h"
#include "my.h"
#include "struct.h"
#include "my_free.h"
#include "macros.h"
#include "epurstr.h"
#include "headlist.h"

char    is_delimiter(char *str, int *i)
{
  while (str[*i] != '\0')
    {
      if (str[*i] == '&' && str[*i + 1] == '&' && str[*i + 2] != '&')
        return (MY_AND);
      else if (str[*i] == '|' && str[*i + 1] == '|' && str[*i + 2] != '|')
        return (MY_OR);
      else if (str[*i] == '|' && str[*i + 1] != '|')
        return (MY_PIPE);
      else if (str[*i] == '<' && str[*i + 1] != '<')
        return (MY_LEFT);
      else if (str[*i] == '>' && str[*i + 1] != '>')
        return (MY_RIGHT);
      else if (str[*i] == '<' && str[*i + 1] == '<' && str[*i + 2] != '<')
        return (MY_DLEFT);
      else if (str[*i] == '>' && str[*i + 1] != '>' && str[*i + 2] != '>')
        return (MY_DRIGHT);
      else if (str[*i] == ';')
        return (MY_DOT);
      else if (str[*i] == '&')
	return (0);
      *i = *i + 1;
    }
  return (0);
}

char    *get_instruction(t_struct *objs, char *str, int save, int *save_i)
{
  char  *new_str;
  int   i;

  i = -1;
  if ((objs->instruction = malloc(sizeof(char) * (save + 1))) == NULL)
    return (NULL);
  while (++i < save)
    objs->instruction[i] = str[i];
  objs->instruction[i] = '\0';
  new_str = my_epurstr(objs->instruction);
  free(objs->instruction);
  objs->instruction = new_str;
  while (str[i++] != '\0');
  if ((new_str = malloc(sizeof(char) * (i - save + 1))) == NULL)
    return (NULL);
  i = save;
  while ((str[i] == '&' || str[i] == '<' || str[i] == '>' ||
        str[i] == '|' || str[i] == ';' || str[i] == ' ') && str[i++] != '\0');
  save = -1;
  while (str[i] != '\0')
    new_str[++save] = str[i++];
  new_str[save + 1] = '\0';
  *save_i = 0;
  free(str);
  return (new_str);
}

char    is_background(char *str, int i)
{
  while (str[i] != '\0')
    {
      if (i == 0 && str[i] == '&' && str[i + 1] != '&')
        return (1);
      else if (i > 0 && str[i] == '&' &&
               str[i + 1] != '&' && str[i - 1] != '&')
        return (1);
      i++;
    }
  return (0);
}

char	*if_statut_1(t_struct *objs, char *str, int *i, int *statut)
{
  int	save_i;

  save_i = *i;
  objs->operateur = is_delimiter(str, i);
  objs->background = is_background(str, save_i);
  str = get_instruction(objs, str, *i, i);
  *statut = 2;
  return (str);
}

t_headlist      *lex_list(t_headlist *headlist, char *cmd)
{
  int           i;
  int           statut;
  t_struct      *objs;
  char		*str;

  i = 0;
  statut = 0;
  str = NULL;
  str = my_strcat(str, cmd);
  headlist = init_headlist(headlist);
  objs = init_struct(headlist, &statut);
  while (str[i] != '\0')
    {
      if (statut == 2)
        objs = add_struct(headlist, &statut);
      else if (statut == 1)
	str = if_statut_1(objs, str, &i, &statut);
      else
	i++;
    }
  free(str);
  return (headlist);
}
