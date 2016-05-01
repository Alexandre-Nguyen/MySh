/*
** mult.c for mult in /home/alexandre/rendu/PSU_2015_minishell2/srcs
** 
** Made by alexandre
** Login   <nguye_0@epitech.net>
** 
** Started on  Sun Apr 10 18:12:11 2016 alexandre
** Last update Tue Apr 12 18:30:55 2016 alexandre
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/fonction.h"

void	mult_traitement(char *buffer, char **env)
{
  int   i;
  char  *recup;

  i = 0;
  buffer = epure_str(buffer);
  while (buffer[0] != '\0')
    {
      recup = recup_arg(buffer);
      buffer = cut_buff(buffer);
      traitement(recup, env);
    }
}

char	*cut_buff(char  *buffer)
{
  char  *new;
  int   i;
  int   j;
  int   a;

  a = 0;
  i = pos_cut(buffer);
  j = my_strlen(buffer);
  if ((new = malloc(sizeof(char) * ((j - i) + 1))) == NULL)
    return (NULL);
  while (buffer[i] != '\0')
    {
      new[a] = buffer[i];
      i = i + 1;
      a = a + 1;
    }
  new[a] = '\0';
  return (new);
}

int	pos_cut(char *buffer)
{
  int   i;

  i = 0;
  while (buffer[i] != ';' && buffer[i] != '\0')
    i = i + 1;
  return (i + 1);
}

char	*recup_arg(char *buffer)
{
  int   i;
  char  *cp;

  i = 0;
  if ((cp = malloc(sizeof(char) * 10 + 1)) == NULL)
    return (NULL);
  if (buffer == NULL)
    return (NULL);
  while (buffer[i] != ';' && buffer[i] != '\0')
    {
      cp[i] = buffer[i];
      i = i + 1;
    }
  cp[i] = '\0';
  return (cp);
}

int	check_tab(char *buffer)
{
  int   i;

  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == ';')
	return (1);
      i = i + 1;
    }
  return (0);
}
