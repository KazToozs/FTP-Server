/*
** c_cwd.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/src/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue May  3 13:49:52 2016 toozs-_c
** Last update Tue May 10 16:10:59 2016 toozs-_c
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
      if (param->words[1] && !stat(param->words[1], &sta)
	  && !access(param->words[1], X_OK) && chdir(param->words[1]) == -1)
	{
          dprintf(param->fd, "550 Failed to change directory.\r\n");
          return (1);
        }
      dprintf(param->fd, "250 Directory successfully changed.\r\n");
      return (0);
    }
  return (2);
}
