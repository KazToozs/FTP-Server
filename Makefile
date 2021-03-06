##
## Makefile for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp
## 
## Made by toozs-_c
## Login   <toozs-_c@epitech.net>
## 
## Started on  Mon May  2 09:55:55 2016 toozs-_c
## Last update Tue May 10 16:48:34 2016 toozs-_c
##

CC              =       gcc

RM              =       rm -f

NAME            =       server

SRCS            +=      ./src/main.c
SRCS		+=	./src/my.c
SRCS		+=	./src/get_next_line.c
SRCS		+=	./src/my_str_tab.c
SRCS		+=	./src/read_commands.c
SRCS		+=	./src/server.c

SRCS		+=	./src/commands/c_cdup.c
SRCS		+=	./src/commands/c_cwd.c
SRCS		+=	./src/commands/c_help.c
SRCS		+=	./src/commands/c_noop.c
SRCS		+=	./src/commands/c_pass.c
SRCS		+=	./src/commands/c_pwd.c
SRCS		+=	./src/commands/c_quit.c
SRCS		+=	./src/commands/c_user.c

OBJS            =       $(SRCS:.c=.o)

CFLAGS          +=      -I./include
CFLAGS          +=      -W -Wall -Wextra -Werror


all:            $(NAME)

$(NAME):        $(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:         clean
		$(RM) $(NAME)

re:     fclean all
