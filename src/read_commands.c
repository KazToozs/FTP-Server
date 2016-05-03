/*
** commands.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/src
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May  2 16:06:42 2016 toozs-_c
** Last update Tue May  3 14:28:02 2016 toozs-_c
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
    /* {"DELE", &_dele}, */
    {"PWD", &_pwd},
    /* {"PASV", &_pasv}, */
    /* {"PORT", &_port}, */
    {"HELP", &_help},
    {"NOOP", &_noop},
    /* {"RETR", &_retr}, */
    /* {"STOR", &_stor}, */
    /* {"LIST", &_list}, */
    {NULL, NULL}
  };

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
