/*
** c_cwd.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/src/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue May  3 13:49:52 2016 toozs-_c
** Last update Sat May 14 18:42:47 2016 toozs-_c
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my_ftp.h"

int		_cwd(t_param *param)
{
  struct stat	sta;

  if (param->logged)
    {
      if (param->words[1])
	{
	  if (stat(param->words[1], &sta) == -1
	      && access(param->words[1], X_OK) == -1
	      && chdir(param->words[1]) == -1)
	    {
	      dprintf(param->fd, "550 Failed to change directory.\r\n");
	      return (1);
	    }
	}
      else
	{
	  dprintf(param->fd, "501 Missing parameter.\r\n");
	  return (1);
	}
      dprintf(param->fd, "250 Directory successfully changed.\r\n");
      return (0);
    }
  return (2);
}
