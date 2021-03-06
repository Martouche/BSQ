/*
** EPITECH PROJECT, 2018
** check_case
** File description:
** special_case and check
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	*special_case(char *buffer)
{
	int i = 0;

	while (buffer[i] != '\0')
	{
		if (buffer[i] == '.')
		{
			buffer[i] = 'x';
			return (buffer);
		}
		else
			i = i + 1;
	}
	return (buffer);
}

int	check_bsq(char *buffer)
{
	int i = 0;
	int nb = my_getnbr(buffer);
	int lines = 0;

	while (buffer[i] != '\n')
		buffer = buffer + 1;
	buffer = buffer + 1;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			lines++;
		else if (buffer[i] != '.' && buffer[i] != 'o' && buffer[i] != '\n')
			return (84);
		i = i + 1;
	}
	if (lines != nb)
		return (84);
	return (0);
}

