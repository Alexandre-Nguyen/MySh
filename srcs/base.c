/*
** base.c for base in /home/alexandre/rendu/PSU_2015_minishell2/srcs
** 
** Made by alexandre
** Login   <nguye_0@epitech.net>
** 
** Started on  Tue Mar 29 18:31:07 2016 alexandre
** Last update Tue Apr 12 19:43:47 2016 alexandre
*/

#include <unistd.h>
#include "../include/fonction.h"
#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int	my_strlen(char *buffer)
{
  int   i;

  i = 0;
  while (buffer[i] != '\0')
    i = i + 1;
  return (i);
}

void	my_printab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != NULL)
    {
      write(1, tab[i], my_strlen(tab[i]));
      write(1, "\n", 1);
      i++;
    }
}

int	reline(char *buffer)
{
  int	i;
  int	word;

  i = 0;
  word = 0;
  if (buffer[i] != ' ' && buffer[i] != '\t')
    word = word + 1;
  while (buffer[i] != '\0')
    {
      if ((buffer[i] == ' ' || buffer[i] == '\t') &&
	  (buffer[i + 1] != ' ' || buffer[i + 1] != '\t'))
	word = word + 1;
      i = i + 1;
    }
  return (word);
}
