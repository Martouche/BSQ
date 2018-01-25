/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_put_nbr.c
*/


#include "bsq.h"

int	my_open(char *file)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		my_error("Error on file oppening !!");
	return (fd);
}

int	cal(int nb, int n)
{
	if (n > 9)
	{
		nb = n % 10;
		cal(nb, n / 10);
	}
	else
		nb = n;
	my_putchar(nb + 48);
	return (nb);
}

void	my_put_nbr(int nb)
{
	if (nb < 0)
	{
		nb = nb * (-1);
		my_putchar('-');
		cal(nb, nb);
	}
	else
		cal(nb, nb);
}
