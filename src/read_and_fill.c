/*
** EPITECH PROJECT, 2018
** check_case
** File description:
** check_case
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int		read_file(char *buffer, char **argv)
{
  struct stat	info;

  if ((stat(argv[1], &info)) == -1)
    return (84);
  if ((buffer = malloc(sizeof(char) * info.st_size + 1)) == NULL)
    return (84);
  if ((read(open(argv[1], O_RDONLY), buffer, info.st_size)) == -1)
    return (84);
  buffer[info.st_size] = '\0';
  check_bsq(buffer);
  close(open(argv[1], O_RDONLY));
  return (information(buffer, info.st_size));
}

int		fill(int min, int tmp, int tmp2)
{
  if (min > tmp)
    min = tmp;
  if (min > tmp2)
    min = tmp2;
  return (min + 1);
}

void		display(char **buffer, int **map, int size, int times)
{
  write(1, *buffer, (size - (times + 1)));
  while (times >= 0)
    {
      *buffer = *buffer - 1;
      times = times - 1;
    }
  free(*buffer);
  free(*map);
}
