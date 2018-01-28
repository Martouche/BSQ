/*
** EPITECH PROJECT, 2018
** mon algo bsq
** File description:
** bsq
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	*resolve(char *buffer, int *map, int width, int coord)
{
	int tmp;
	int lines = 0;

	while (lines != map[coord])
	{
		tmp = coord - (map[coord] - 1);
		while (tmp <= coord)
		{
			buffer[tmp - (lines * width)] = 'x';
			tmp = tmp + 1;
		}
		lines++;
	}
	return (buffer);
}

char	*bsq(char *buffer, int *map, int width)
{
	int i = 0;

	while (buffer[i] != '\n')
	{
		map[i] = (buffer[i] == '.') ? 1 : 0;
		i = i + 1;
	}
	while (buffer[i] != '\0')
	{
		if (buffer[i - 1] == '\n')
			map[i] = (buffer[i] == '.') ? 1 : 0;
		else if (buffer[i] == '\n')
			map[i] = -1;
		else
			map[i] = 0;
		i = i + 1;
	}
	map[i] = END;
	buffer = bomberman(buffer, map, width);
	return (buffer);
}

int	main(int argc, char **argv)
{
	char *buffer;

	if (argc != 2)
		return (84);
	buffer = NULL;
	return (read_file(buffer, argv));
}
