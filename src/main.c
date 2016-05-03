/*
** main.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/test
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May  2 10:39:01 2016 toozs-_c
** Last update Tue May  3 13:39:59 2016 toozs-_c
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include "my_ftp.h"
#include "my.h"

int				handle_client(int client_fd,
					      struct in_addr sin_addr)
{
  /* static const char * const	welcome = "220 Your IP address is "; */
  char				*client_ip;
  t_param			params;
  char				*ret;
  char				**tab;
  int				end;

  client_ip = inet_ntoa(sin_addr);
  set_params(&params, client_fd);
  write(1, client_ip, strlen(client_ip));
  write(1, "\n", 1);
  dprintf(client_fd, "220 Your IP address is %s\r\n", client_ip);
  /* if (write(client_fd, welcome, strlen(welcome)) == -1 */
  /*     || write(client_fd, client_ip, strlen(client_ip)) == -1 */
  /*     || write(client_fd, "\r\n", 1) == -1) */
  /*   return (1); */
  end = 0;
  while (!end && (ret = get_next_line(client_fd)))
    {
      tab = my_str_tab(ret);
      params.words = tab;
      if (check_commands(&params) == 3)
	end = 1;
      free(ret);
      free_tab(tab);
    }
  if (params.name)
    free(params.name);
  return (0);
}

int			make_socket(int port, struct sockaddr_in *s_in)
{
  struct protoent	*pe;
  int			stat;
  int			fd;

  if ((pe = getprotobyname("TCP")) == NULL)
    return (1);
  s_in->sin_family = AF_INET;
  s_in->sin_port = htons(port);
  s_in->sin_addr.s_addr = INADDR_ANY;
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (1);
  stat = 1;
  if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
		 &stat, sizeof(int)) < 0)
    return (1);
  return (fd);
}

int			check_return(int first, int second)
{
  if (first == -1)
    {
      if (close(second) == -1)
	return (1);
      return (1);
    }
  return (0);
}

int			server_loop(int fd, int *client_fd,
				    struct sockaddr_in *s_in_client)
{
  pid_t			child;
  socklen_t		s_in_size;

  child = -1;
  s_in_size = sizeof(*s_in_client);
  while (child != 0)
    {
      *client_fd = accept(fd, (struct sockaddr *)s_in_client, &s_in_size);
      if (check_return(*client_fd, fd))
	return (1);
      if ((child = fork()) == -1)
	return (1);
      if (child > 0)
	if (close(*client_fd) == -1)
	  return (1);
    }
  return (0);
}

int			run_server(int port)
{
  int			fd;
  struct sockaddr_in	s_in;
  struct sockaddr_in	s_in_client;
  int			client_fd;

  if ((fd = make_socket(port, &s_in)) == 1)
    return (1);
  if (check_return(bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)), fd))
    return (1);
  if (check_return(listen(fd, 42), fd))
    return (1);
  if (server_loop(fd, &client_fd, &s_in_client) == 0)
    handle_client(client_fd, s_in_client.sin_addr);
  if (close(fd) == -1)
    return (1);
  if (close(client_fd) == -1)
    return (1);
  return (0);
}

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
