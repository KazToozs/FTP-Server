/*
** c_quit.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/src/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue May  3 13:17:04 2016 toozs-_c
** Last update Tue May  3 13:22:02 2016 toozs-_c
*/

#include <stdio.h>
#include "my_ftp.h"

int		_quit(t_param *param)
{
  dprintf(param->fd, "221 Goodbye\r\n");
  return (3);
}
