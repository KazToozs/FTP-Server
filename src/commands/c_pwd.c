/*
** c_pwd.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/src/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue May  3 13:57:48 2016 toozs-_c
** Last update Tue May  3 14:10:30 2016 toozs-_c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_ftp.h"

int		_pwd(t_param *param)
{
  char		name[1024];

  if (param->logged)
    {
      getcwd(name, 1024);
      dprintf(param->fd, "257 \"%s\"\r\n", name);
      return (0);
    }
  return (2);
}
