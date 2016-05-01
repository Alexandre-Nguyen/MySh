/*
** first.c for fist in /home/alexandre/rendu/PSU_2015_minishell2/srcs
** 
** Made by alexandre
** Login   <nguye_0@epitech.net>
** 
** Started on  Tue Mar 29 18:31:41 2016 alexandre
** Last update Tue Apr 12 18:10:23 2016 alexandre
*/

#include "../include/fonction.h"

int	linepath(char *path)
{
  int   i;
  int   line;

  i = 0;
  line = 0;
  while (path[i] != '\0')
    {
      if (path[i] == ':')
        line = line + 1;
      i = i + 1;
    }
  return (line + 1);
}

int	compare_exit(char *buffer)
{
  int   a;
  char  *str_exit = "exit";

  a = 0;
  while (str_exit[a] != '\0')
    {
      if (str_exit[a] == buffer[a])
        a = a + 1;
      else
        return (5);
    }
  return (0);
}

int	first_exec(char **tab)
{
  if (tab[0][0] == '/' || (tab[0][0] == '.' && tab[0][1] == '/'))
    return (3);
  else
    return (2);
}

int	current_directory(char **tab)
{
  char	*t;

  if (tab[0][0] == 'c' && tab[0][1] == 'd' && tab[0][2] == '\0')
    {
      if ((t = malloc(sizeof(char) * 102)) == NULL)
	exit (0);
      getcwd(t, 100);
      t[100] = '/';
      t[101] = '\0';
      chdir(tab[1]);
      return (3);
    }
  else
    return (2);
}

char	*epure_str(char *str)
{
  t_tab	epur;

  epur.i = 0;
  epur.l = 0;
  epur.x = 0;
  epur.size = my_strlen(str);
  if ((epur.test = malloc(sizeof(char) * epur.size + 1)) == NULL)
    return (0);
  epur.test[epur.size] = '\0';
  second_epure(&epur, str);
  while (str[epur.i] != '\0')
    {
      first_epure(&epur, str);
      epur.x = 0;
      while ((str[epur.i] == ' ' || str[epur.i] == '\t')
	     && str[epur.i] != '\0')
        epur.i = epur.i + 1;
      while ((str[epur.i] != ' ' && str[epur.i] != '\t') && str[epur.i] != '\0')
        {
          epur.test[epur.l] = str[epur.i];
          epur.i = epur.i + 1;
          epur.l = epur.l + 1;
        }
    }
  return (epur.test);
}
