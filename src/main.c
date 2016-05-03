/*
** main.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/src
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue May  3 16:33:09 2016 toozs-_c
** Last update Tue May  3 16:34:39 2016 toozs-_c
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_ftp.h"

int			main(int ac, char **av)
{
  int			port;

  if (ac == 3)
    {
      if (chdir(av[2]) == -1)
        return (1);
      port = atoi(av[1]);
      run_server(port);
    }
  return (0);
}
