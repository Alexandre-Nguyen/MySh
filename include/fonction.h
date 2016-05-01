/*
** fonction.h for fonction in /home/alexandre/rendu/PSU_2015_minishell2/include
** 
** Made by alexandre
** Login   <nguye_0@epitech.net>
** 
** Started on  Tue Mar 29 18:33:15 2016 alexandre
** Last update Fri Apr 15 00:31:55 2016 alexandre
*/

#ifndef FONCTION_H_
# define FONCTION_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

typedef struct		s_tab
{
  int	i;
  int	l;
  int	x;
  int	y;
  int	size;
  char	*test;
}			t_tab;

typedef struct		s_traite
{
  char  *path;
  char  *exec;
  char  *buff;
  char	**tab;
  char	*tmp;
  int   pid;
  int   statut;
  int   verif;
  int   first;
}			t_traite;

char	*find_path(char **env, char *path);
char	*str_glue(char  *origin, char *glue);
char	*epure_str(char *str);
void	restrtab(t_tab *tab, char **new);
char	**strtab(char *buffer);
void	restrtab_path(t_tab *tab, char **tabpath);
char	**strtab_path(char *path);
char	*test(char *path, char *tab);
void	traitement(char *buffer, char **env);
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *buffer);
void	my_printab(char **tab);
int	reline(char *buffer);
int	line(char *buffer);
int	linepath(char *path);
int	compare_exit(char *buffer);
int	first_exec(char **tab);
int	current_directory(char **tab);
int	space_end(int   i, char *str);
void	first_epure(t_tab *epur, char *str);
pid_t	wait(int *status);
void	second_epure(t_tab *epur, char *str);
void	mult_traitement(char *buffer, char **env);
char	*cut_buff(char  *buffer);
int	pos_cut(char *buffer);
char	*recup_arg(char *buffer);
int     check_tab(char *buffer);
char	*strcp(char *buffer);
char	*recup_arg_pipe(char *buffer);
char	*cut_buff_pipe(char  *buffer);
char	*strcp(char *buffer);
int	the_exit(char *tab);
void	base_condition(char *buffer, char **env);
void	incre(t_tab *tab);
int	pos_cut_pipe(char *buffer);
int	check_pipe(char *buffer);
void	first_pipe_traitement(char *buffer, char **env,
			      t_traite *tr, int pipefd[2]);
void	second_pipe_traitement(char *buffer, char **env,
			       t_traite *tr, int pipefd[2]);
void	pipe_traitement(char *buffer, char **env);
int	pip_traitement(char *buffer, char **env);

#endif
