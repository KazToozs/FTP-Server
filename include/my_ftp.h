/*
** my_ftp.h for my_ftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/include
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May  2 22:08:31 2016 toozs-_c
** Last update Tue May  3 13:04:51 2016 toozs-_c
*/

#ifndef __MYFTP
#define __MYFTP

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

/*
** COMMANDS
*/

int		_noop(t_param *param);
int		_user(t_param *param);
int		_cwd(t_param *param);
int		_cdup(t_param *param);
int		_quit(t_param *param);
int		_dele(t_param *param);
int		_pwd(t_param *param);
int		_pasv(t_param *param);
int		_pass(t_param *param);
int		_port(t_param *param);
int		_help(t_param *param);
int		_noop(t_param *param);
int		_retr(t_param *param);
int		_stor(t_param *param);
int		_list(t_param *param);

#endif
