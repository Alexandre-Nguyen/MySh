/*
** final.c for final in /home/alexandre/rendu/PSU_2015_minishell2/srcs
** 
** Made by alexandre
** Login   <nguye_0@epitech.net>
** 
** Started on  Tue Mar 29 18:31:26 2016 alexandre
** Last update Fri Apr 15 00:14:09 2016 alexandre
*/

#include "../include/fonction.h"

void	incre(t_tab *tab)
{
  tab->i = tab->i + 1;
  tab->y = tab->y + 1;
}

char	**strtab(char *buffer)
{
  char  **new;
  t_tab tab;

  tab.x = 0;
  tab.i = 0;
  tab.y = 0;
  tab.size = my_strlen(buffer);
  tab.l = reline(buffer);
  if ((new = malloc(sizeof(char *) * (tab.l + 1))) == NULL)
    return (0);
  while (buffer[tab.i] != '\0')
    {
      if ((new[tab.x] = malloc(sizeof(char) * (tab.size + 1))) == NULL)
        return (0);
      new[tab.x][tab.size] = '\0';
      while ((buffer[tab.i] != ' ' && buffer[tab.i] != '\t')
	     && buffer[tab.i] != '\0')
        {
          new[tab.x][tab.y] = buffer[tab.i];
	  incre(&tab);
        }
      restrtab(&tab, new);
    }
  new[tab.l] = NULL;
  return (new);
}

void	second_epure(t_tab *epur, char *str)
{
  if (str[epur->i] == ' ' || str[epur->i] == '\t')
    {
      while (str[epur->i] == ' ' || str[epur->i] == '\t')
        epur->i = epur->i + 1;
    }
}
