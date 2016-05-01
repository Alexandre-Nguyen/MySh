/*
** base2.c for base2 in /home/alexandre/rendu/PSU_2015_minishell2/srcs
** 
** Made by alexandre
** Login   <nguye_0@epitech.net>
** 
** Started on  Tue Apr 12 19:40:43 2016 alexandre
** Last update Fri Apr 15 00:19:20 2016 alexandre
*/

#include "../include/fonction.h"

char	*strcp(char *buffer)
{
  char  *tmp;
  int   i;

  i = 0;
  if ((tmp = malloc(sizeof(buffer) + 1)) == NULL)
    return (NULL);
  while (buffer[i] != '\0')
    {
      tmp[i] = buffer[i];
      i = i + 1;
    }
  return (tmp);
}

int	the_exit(char *tab)
{
  int   i;

  i = 0;
  while (tab[i] != '\0')
    {
      if (tab[i] == 'e' && tab[i + 1] == 'x' &&
	  tab[i + 2] == 'i' && tab[i + 3] == 't')
	exit(0);
      i = i + 1;
    }
  return (1);
}

void	base_condition(char *buffer, char **env)
{
  if ((check_pipe(buffer)) != 0)
    pip_traitement(buffer, env);
  else if ((check_tab(buffer)) == 0 && (check_pipe(buffer)) == 0)
    traitement(buffer, env);
  else if ((check_tab(buffer)) == 1)
    mult_traitement(buffer, env);
}
