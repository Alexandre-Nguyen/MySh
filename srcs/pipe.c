/*
** pipe.c for pipe in /home/alexandre/rendu/PSU_2015_minishell2/srcs
** 
** Made by alexandre
** Login   <nguye_0@epitech.net>
** 
** Started on  Sun Apr 10 18:25:29 2016 alexandre
** Last update Tue Apr 12 18:35:05 2016 alexandre
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/fonction.h"

void	first_pipe_traitement(char *buffer, char **env,
			      t_traite *tr, int pipefd[2])
{
  int	tst;
  int	directory;
  int	error;

  error = pipe(pipefd);
  if (error == -1)
    exit(EXIT_FAILURE);
  if ((tr->pid = fork()) == -1)
    exit(EXIT_FAILURE);
  if (tr->pid == 0)
    {
      tr->buff = epure_str(buffer);
      tr->tab = strtab(tr->buff);
      tr->path = find_path(env, tr->path);
      directory = current_directory(tr->tab);
      if (directory == 2)
	tr->exec = test(tr->path, tr->tab[0]);
      close(pipefd[0]);
      dup2(pipefd[1], 1);
      execve(tr->exec, tr->tab, env);
      exit(0);
    }
  waitpid(tr->pid, &tst, 0);
}

void	second_pipe_traitement(char *buffer, char **env,
			       t_traite *tr, int pipefd[2])
{
  int	tst;
  int	directory;

  if ((tr->pid = fork()) == -1)
    exit(EXIT_FAILURE);
  if (tr->pid == 0)
    {
      buffer = tr->tmp;
      buffer = cut_buff_pipe(buffer);
      tr->buff = epure_str(buffer);
      tr->tab = strtab(tr->buff);
      tr->path = find_path(env, tr->path);
      directory = current_directory(tr->tab);
      if (directory == 2)
	tr->exec = test(tr->path, tr->tab[0]);
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      execve(tr->exec, tr->tab, env);
      exit(0);
    }
  close(pipefd[1]);
  close(pipefd[0]);
  wait(&tr->statut);
  if (WIFSIGNALED(tr->statut))
    my_putstr("Segmentation fault\n");
}

void	pipe_traitement(char *buffer, char **env)
{
  t_traite      tr;
  int	pipefd[2];

  tr.tmp = strcp(buffer);
  buffer = recup_arg_pipe(buffer);
  first_pipe_traitement(buffer, env, &tr, pipefd);
  second_pipe_traitement(buffer, env, &tr, pipefd);
}

int	pip_traitement(char *buffer, char **env)
{
  pipe_traitement(buffer, env);
}
