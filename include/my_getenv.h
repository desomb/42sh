/*
** my_getenv.h for my_getenv in /home/quero_q/Dropbox/progra/42/lexer_42/include
** 
** Made by quero_q
** Login   <quero_q@epitech.net>
** 
** Started on  Thu May 21 13:46:16 2015 quero_q
** Last update Sun May 24 22:01:43 2015 François Colin
*/

#ifndef _MY_GETENV_H_
#define _MY_GETENV_H_ value

void	aff_my_env(char **tab);
void	my_free_env(char **my_env);
char	**my_getenv(char **environ);
int	check_builtins(char *str, char ***env);

#endif /*_MY_GETENV_H_*/
