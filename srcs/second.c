/*
** second.c for second in /home/alexandre/rendu/PSU_2015_minishell2/srcs
** 
** Made by alexandre
** Login   <nguye_0@epitech.net>
** 
** Started on  Tue Mar 29 18:31:57 2016 alexandre
** Last update Tue Apr 12 19:45:41 2016 alexandre
*/

#include "../include/fonction.h"

char	*find_path(char **env, char *path)
{
  t_tab find;

  find.x = 0;
  find.y = 0;
  find.i = 0;
  if ((path = malloc(sizeof(char) * 100)) == NULL)
    return (0);
  while (env[find.x] != NULL)
    {
      while (env[find.x][find.y] != '\0')
        {
          if (env[find.x][0] == 'P' && env[find.x][1] == 'A' &&
              env[find.x][2] == 'T' && env[find.x][3] == 'H')
            {
              path[find.i] = env[find.x][find.y];
              find.i = find.i + 1;
            }
          find.y = find.y + 1;
        }
      find.y = 0;
      find.x = find.x + 1;
    }
  path[find.i + 1] = '\0';
  return (path);
}

void	restrtab(t_tab *tab, char **new)
{
  tab->i = tab->i + 1;
  new[tab->x][tab->y] = '\0';
  tab->y = 0;
  tab->x = tab->x + 1;
}

void	restrtab_path(t_tab *tab, char **tabpath)
{
  tab->i = tab->i + 1;
  tabpath[tab->x][tab->y] = '/';
  tabpath[tab->x][tab->y + 1] = '\0';
  tab->y = 0;
  tab->x = tab->x + 1;
}

int	space_end(int   i, char *str)
{
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
        return (2);
      i = i + 1;
    }
  return (3);
}

void	first_epure(t_tab *epur, char *str)
{
  if ((str[epur->i] == ' ' || str[epur->i] == '\t')
      && str[epur->i + 1] != '\0')
    {
      epur->x = space_end(epur->i, str);
      if (epur->x == 2)
        epur->test[epur->l] = str[epur->i];
      epur->i = epur->i + 1;
      epur->l = epur->l + 1;
    }
}
