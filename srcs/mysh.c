/*
** mysh.c for mysh in /home/alexandre/rendu/PSU_2015_minishell2/srcs
** 
** Made by alexandre
** Login   <nguye_0@epitech.net>
** 
** Started on  Tue Mar 29 18:30:56 2016 alexandre
** Last update Fri Apr 15 00:20:07 2016 alexandre
*/

#include "../include/fonction.h"

char	**strtab_path(char *path)
{
  char	**tabpath;
  t_tab	tab;

  tab.l = linepath(path);
  tab.i = 5;
  tab.x = 0;
  tab.y = 0;
  tab.size = my_strlen(path);
  if ((tabpath = malloc(sizeof(char *) * tab.l + 1)) == NULL)
    return (0);
  while (path[tab.i] != '\0')
    {
      if ((tabpath[tab.x] = malloc(sizeof(char) * tab.size + 1)) == NULL)
        return (0);
      while (path[tab.i] != ':' && path[tab.i] != '\0')
        {
          tabpath[tab.x][tab.y] = path[tab.i];
          tab.i = tab.i + 1;
          tab.y = tab.y + 1;
        }
      restrtab_path(&tab, tabpath);
    }
  tabpath[tab.l] = NULL;
  return (tabpath);
}

char	*str_glue(char	*origin, char *glue)
{
  char	*new;
  int	glue_size;
  int	origin_size;
  t_tab	tab;

  tab.i = 0;
  tab.l = 0;
  glue_size = my_strlen(glue);
  origin_size = my_strlen(origin);
  tab.size = glue_size + origin_size;
  if ((new = malloc(sizeof(char) * tab.size + 1)) == NULL)
    return (0);
  while (origin[tab.i] != '\0')
    {
      new[tab.i] = origin[tab.i];
      tab.i = tab.i + 1;
    }
  while (glue[tab.l] != '\0')
    {
      new[tab.i] = glue[tab.l];
      tab.i = tab.i + 1;
      tab.l = tab.l + 1;
    }
  new[tab.i] = '\0';
  return (new);
}

char	*test(char *path, char *tab)
{
  char	**allpath;
  t_tab	test;
  char	*check;
  int	verif;

  test.i = 0;
  test.x = 0;
  test.y = 0;
  allpath = strtab_path(path);
  while (allpath[test.x] != NULL)
    {
      the_exit(tab);
      check = str_glue(allpath[test.x], tab);
      verif = access(check, F_OK);
      if (verif == 0)
	return (check);
      free(check);
      test.x = test.x + 1;
    }
  my_putstr("commmand not found\n");
  return (0);
}

void	traitement(char *buffer, char **env)
{
  char	**tab;
  t_traite	tr;
  int	directory;

  tr.buff = epure_str(buffer);
  tab = strtab(tr.buff);
  tr.path = find_path(env, tr.path);
  directory = current_directory(tab);
  if (directory == 2)
    tr.exec = test(tr.path, tab[0]);
  if ((tr.pid = fork()) == -1)
    exit(EXIT_FAILURE);
  if (tr.pid == 0)
    execve(tr.exec, tab, env);
  else if (tr.pid > 0)
    {
      wait(&tr.statut);
      if (WIFSIGNALED(tr.statut))
	my_putstr("Segmentation fault\n");
    }
}

int	main(int argc, char **argv, char **env)
{
  char	buffer[4097];
  int	a;
  int	b;

  (void)argc;
  (void)argv;
  while (1)
    {
      my_putstr("$>");
      b = 0;
      if ((a = read(0, buffer, 4096)) == -1 || a == 0)
	return (0);
      buffer[a - 1] = '\0';
      if (buffer[0] == '\0' ||
	  (buffer[0] == ' ' && buffer[1] == '\0'))
	b = 1;
      else if (b == 0)
	base_condition(buffer, env);
    }
}
