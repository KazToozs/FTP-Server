/*
** c_user.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/src/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue May  3 10:41:03 2016 toozs-_c
** Last update Tue May  3 13:02:20 2016 toozs-_c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_ftp.h"

int		_user(t_param *param)
{
  if (param->logged == 0)
    {
      if (param->words[1])
	{
	  if (param->name)
	    free(param->name);
	  param->name = strdup(param->words[1]);
	  dprintf(param->fd, "331 Please specify the password.\r\n");
	  return (0);
	}
      else
	dprintf(param->fd, "530 Permission denied.\r\n");
      if (param->name)
	free(param->name);
      param->name = NULL;
    }
  else
    dprintf(param->fd, "530 Can't change from guest user.\r\n");
  return (1);
}
