/*
** EPITECH PROJECT, 2018
** my_indform
** File description:
** my_inform
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int		information(char *buffer, int size)
{
	int lines = my_getnbr(buffer);
	int i = 0;
	int times = 0;
	int *map;

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
	buffer = (lines == 1 || i == 2) ? special_case(buffer)
		: bsq(buffer, map, i);
	display(&buffer, &map, size, times);
	return (0);
}
char *bomberman(char *buffer, int *map, int width)
{
	int i = 0;
	int coord = 0;

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
			map[i] = fill(map[i - 1], map[i - width],
				      map[i - (width + 1)]);
			if (map[coord] < map[i])
				coord = i;
			i = i + 1;
		}
	}
	buffer = resolve(buffer, map, width, coord);
	return (buffer);
}
