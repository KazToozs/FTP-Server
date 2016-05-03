/*
** main.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/test
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May  2 10:39:01 2016 toozs-_c
** Last update Mon May  2 13:24:28 2016 toozs-_c
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int				handle_client(int client_fd,
					      char const *client_ip)
{
  static const char * const	welcome = "Welcome!\n Your IP address is ";

  if (write(client_fd, welcome, strlen(welcome)) == -1
      || write(client_fd, client_ip, strlen(client_ip)) == -1
      || write(client_fd, "\n", 1) == -1)
    return (1);
  return (0);
}

int			do_test(int port)
{
  struct protoent	*pe;
  int			fd;
  struct sockaddr_in	s_in;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  int			client_fd;
  char			*client_ip;

  if ((pe = getprotobyname("TCP")) == NULL)
    return (1);
  s_in_size = sizeof(s_in_client);
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  /* inet_pton(AF_INET, "0.0.0.0", &s_in.sin_addr.s_addr); */
  if (fd == -1)
    return (1);
  if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }
  if (listen(fd, 42) == -1)
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }
  client_fd = accept(fd, (struct sockaddr *)&s_in_client, &s_in_size);
  if (client_fd == -1)
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }
  client_ip = inet_ntoa(s_in_client.sin_addr);
  write(1, client_ip, strlen(client_ip));
  write(1, "\n", 1);
  handle_client(client_fd, client_ip);
  if (close(fd) == -1)
    return (1);
  if (close(fd) == -1)
    return (1);
  return (0);
}

int			main(int ac, char **av)
{
  int			port;

  if (ac == 2)
    {
      port = atoi(av[1]);
      do_test(port);
    }
  return (0);
}
