/*
** c_cdup.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/src/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue May  3 13:45:18 2016 toozs-_c
** Last update Tue May  3 13:53:40 2016 toozs-_c
*/

#include <unistd.h>
#include <stdio.h>
#include "my_ftp.h"

int		_cdup(t_param *param)
{
  if (param->logged)
    {
      if (chdir("..") == -1)
	{
	  dprintf(param->fd, "550 Failed to change directory.\r\n");
	  return (1);
	}
      dprintf(param->fd, "250 Directory successfully changed.\r\n");
      return (0);
    }
  return (2);
}
