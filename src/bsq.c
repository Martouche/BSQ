/*
** EPITECH PROJECT, 2018
** mon algo bsq
** File description:
** bsq
*/


#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char		*resolve(char *buffer, int *map, int width, int coord)
{
	int		tmp;
	int		lines;

	lines = 0;
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

char		*bomberman(char *buffer, int *map, int width)
{
	int		i;
	int		coord;

	i = 0;
	coord = 0;
	while (buffer[i] != '\n')
		i = i + 1;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n' && buffer[i + 1] != '\0')
			i = i + 2;
		if (buffer[i] == 'o')
			i = i + 1;
		else
		{
			map[i] = fill(map[i - 1], map[i - width], map[i - (width + 1)]);
			if (map[coord] < map[i])
				coord = i;
			i = i + 1;
		}
	}
	buffer = resolve(buffer, map, width, coord);
	return (buffer);
}

char		*bsq(char *buffer, int *map, int width)
{
	int		i;

	i = 0;
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

int		information(char *buffer, int size)
{
	int		lines;
	int		i;
	int		times;
	int		*map;

	i = 0;
	times = 0;
	lines = my_getnbr(buffer);
	while (buffer[i] != '\n')
	{
		buffer = buffer + 1;
		times = times + 1;
	}
	buffer = buffer + 1;
	while (buffer[i] != '\n')
		i = i + 1;
	i = i + 1;
	if ((map = malloc(sizeof(int) * (i * lines + 1))) == NULL)
		return (84);
	buffer = (lines == 1 || i == 2) ? special_case(buffer) : bsq(buffer, map, i);
	display(&buffer, &map, size, times);
	return (0);
}

int		main(int argc, char **argv)
{
	char		*buffer;

	if (argc != 2)
		return (84);
	buffer = NULL;
	return (read_file(buffer, argv));
}
