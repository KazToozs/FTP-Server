/*
** c_noop.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/src/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue May  3 10:25:22 2016 toozs-_c
** Last update Tue May  3 16:31:56 2016 toozs-_c
*/

#include <stdio.h>
#include "my_ftp.h"

int		_noop(t_param *param)
{
  if (param->logged == 1)
    {
      dprintf(param->fd, "200 NOOP ok.\r\n");
      return (0);
    }
  else
    return (2);
}
