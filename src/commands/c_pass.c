/*
** c_pass.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/src/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue May  3 10:39:27 2016 toozs-_c
** Last update Tue May 10 15:02:12 2016 toozs-_c
*/

#include <string.h>
#include <stdio.h>
#include "my_ftp.h"

int		_pass(t_param *param)
{
  char		*name;

  if (param->name == NULL)
    {
      dprintf(param->fd, "530 Login with USER first.\r\n");
      return (1);
    }
  if (param->words[1] == NULL)
    {
      name = upper_case(param->name);
      if (!strcmp(name, "ANONYMOUS"))
	{
	  param->logged = 1;
	  dprintf(param->fd, "230 Login successful.\r\n");
	  return (0);
	}
    }
  dprintf(param->fd, "530 Login incorrect.\r\n");
  return (1);
}
