/*
** commands.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/src
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May  2 16:06:42 2016 toozs-_c
** Last update Tue May 10 16:39:13 2016 toozs-_c
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "my_ftp.h"

static t_com g_coms[] =
  {
    {"USER", &_user},
    {"PASS", &_pass},
    {"CWD", &_cwd},
    {"CDUP", &_cdup},
    {"QUIT", &_quit},
    {"PWD", &_pwd},
    {"HELP", &_help},
    {"NOOP", &_noop},
    {NULL, NULL}
  };

void		print_ip(int client_fd, struct in_addr sin_addr)
{
  char		*client_ip;

  client_ip = inet_ntoa(sin_addr);
  dprintf(1, "%s\n", client_ip);
  dprintf(client_fd, "220 Your IP address is %s\r\n", client_ip);
}

void		set_params(t_param *param, int fd)
{
  param->fd = fd;
  param->name = NULL;
  param->pass = NULL;
  param->logged = 0;
}

char		*upper_case(char *word)
{
  int		i;

  if (word)
    {
      i = 0;
      while (word[i] != '\0')
	{
	  if (word[i] >= 'a' && word[i] <= 'z')
	    word[i] = word[i] - 32;
	  i++;
	}
    }
  return (word);
}

int		handle_empty(t_param params)
{
  if (params.logged)
    {
      dprintf(params.fd, "500 Unknown command.\r\n");
    }
  else
    dprintf(params.fd, "530 Please login with USER and PASS.\r\n");
  return (1);
}

int		check_commands(t_param *params)
{
  int		i;
  int		ret;

  i = 0;
  params->words[0] = upper_case(params->words[0]);
  while (g_coms[i].command != NULL
	 && strcmp(g_coms[i].command, params->words[0]) != 0)
    i++;
  if (g_coms[i].command != NULL)
    ret = g_coms[i].ptr(params);
  else
    dprintf(params->fd, "500 Unknown command.\r\n");
  if (ret == 3)
    return (3);
  if (ret == 2)
    dprintf(params->fd, "530 Please login with USER and PASS\r\n");
  return (0);
}
