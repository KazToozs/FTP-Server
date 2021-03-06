/*
** my_strdup.c for myftp in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myftp/src
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May  2 23:23:24 2016 toozs-_c
** Last update Mon May  2 23:23:25 2016 toozs-_c
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	n;

  if (str == NULL)
    return (0);
  n = 0;
  while (str[n] != '\0')
    n++;
  return (n);
}

char	*my_strcpy(char *dest, char *src)
{
  int	n;

  n = 0;
  while (src[n] != '\0')
    {
      dest[n] = src[n];
      n = n + 1;
    }
  return (dest);
}

char	*my_strdup(char *str)
{
  char	*dest;

  if ((dest = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  dest = my_strcpy(dest, str);
  dest[my_strlen(str)] = 0;
  return (dest);
}
