##
## Makefile for make in /home/alexandre/rendu/PSU_2015_minishell2
##
## Made by alexandre
## Login   <nguye_0@epitech.net>
##
## Started on  Tue Mar 29 16:02:42 2016 alexandre
## Last update Fri Apr 15 00:22:28 2016 alexandre
##

CC	= gcc

RM	= rm -f

NAME	= mysh

SRCS	= srcs/base.c \
	  srcs/base2.c \
	  srcs/final.c \
	  srcs/first.c \
	  srcs/mysh.c \
	  srcs/second.c \
	  srcs/mult.c \
	  srcs/pipe.c \
	  srcs/pipe2.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean :clean
	$(RM) $(NAME)

re: fclean all

