/*
** pipe2.c for pipe2 in /home/alexandre/rendu/PSU_2015_minishell2/srcs
** 
** Made by alexandre
** Login   <nguye_0@epitech.net>
** 
** Started on  Tue Apr 12 16:32:22 2016 alexandre
** Last update Tue Apr 12 18:32:01 2016 alexandre
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/fonction.h"

int	pos_cut_pipe(char *buffer)
{
  int   i;

  i = 0;
  while (buffer[i] != '|' && buffer[i] != '\0')
    i = i + 1;
  return (i + 1);
}

char	*recup_arg_pipe(char *buffer)
{
  int   i;
  char  *cp;

  i = 0;
  if ((cp = malloc(sizeof(char) * 10 + 1)) == NULL)
    return (NULL);
  if (buffer == NULL)
    return (NULL);
  while (buffer[i] != '|' && buffer[i] != '\0')
    {
      cp[i] = buffer[i];
      i = i + 1;
    }
  cp[i] = '\0';
  return (cp);
}

char	*cut_buff_pipe(char  *buffer)
{
  char  *new;
  int   i;
  int   j;
  int   a;

  a = 0;
  i = pos_cut_pipe(buffer);
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

int	check_pipe(char *buffer)
{
  int   i;
  int	count;

  count = 0;
  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '|')
	count = count + 1;
      i = i + 1;
    }
  if (count == 1)
    return (1);
  else
    return (0);
}
