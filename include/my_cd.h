/*
** my_cd.h for cd in /home/colin_h/rendu/On_going_project/PSU_2014_42sh
** 
** Made by François Colin
** Login   <colin_h@epitech.net>
** 
** Started on  Fri May 22 19:51:25 2015 François Colin
** Last update Sun May 24 17:06:43 2015 François Colin
*/

#ifndef _MY_CD_H_
#define _MY_CD_H_

char    *new_pwd(char **env, char *str);
char	***my_cd(char **tab, char ***env);
char    **change_oldpwd(char **env);

#endif /* _MY_CD_H_ */
