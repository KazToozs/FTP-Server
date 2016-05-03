/*
** c_help.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/src/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue May  3 14:21:48 2016 toozs-_c
** Last update Tue May  3 14:29:15 2016 toozs-_c
*/

#include <stdio.h>
#include "my_ftp.h"

int		_help(t_param *param)
{
  if (param->logged)
    {
      dprintf(param->fd, "214-The following commands are recognized.\r\n"
	      "USER PASS CWD CDUP QUIT PWD NOOP HELP\r\n"
	      "214 Help OK.\r\n");
      return (0);
    }
  return (2);
}
