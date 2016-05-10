/*
** my_ftp.h for my_ftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/include
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May  2 22:08:31 2016 toozs-_c
** Last update Tue May 10 16:38:59 2016 toozs-_c
*/

#ifndef __MYFTP
#define __MYFTP

#include <arpa/inet.h>

typedef struct	s_param
{
  char		**words;
  int		fd;
  char		*name;
  char		*pass;
  int		logged;
}		t_param;

typedef	struct	s_com
{
  char		*command;
  int		(*ptr)(t_param*);
}		t_com;

char	*get_next_line(int fd);
char	**my_str_tab(char *str);
int	check_commands(t_param *params);
void	set_params(t_param *params, int fd);
char	*upper_case(char *word);
int	run_server(int port);
void	print_ip(int client_fd, struct in_addr sin_addr);
int	handle_empty(t_param params);

/*
** COMMANDS
*/

int		_noop(t_param *param);
int		_user(t_param *param);
int		_cwd(t_param *param);
int		_cdup(t_param *param);
int		_quit(t_param *param);
int		_pwd(t_param *param);
int		_pass(t_param *param);
int		_help(t_param *param);
int		_noop(t_param *param);

#endif
