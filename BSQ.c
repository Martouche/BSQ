/*
** EPITECH PROJECT, 2017
** read file
** File description:
** read file
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int	main(int ac, char **av)
{
	FILE* fichier = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fichier = fopen("test.txt", "r");

	if (fichier == NULL)
		return (84);
	while ((read = getline(&line, &len, fichier))  != -1)
				 printf("%s", line);
	free(line);
	fclose(fichier);
	return (0);
}
