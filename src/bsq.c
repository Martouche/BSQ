/*
** EPITECH PROJECT, 2018
** algo BSQ
** File description:
** mon bsq
*/

#include "bsq.h"

int	check_o(t_bsq bsq)
{
	int	x = bsq.x1;
	int	y = bsq.y1;

	if (bsq.s[y * bsq.len_y + x] == 'o')
		return (x);
	while (y <= bsq.y2)
	{
		if (bsq.s[y * bsq.len_y + bsq.x2] == 'o')
			return (bsq.x2);
		y += 1;
	}
	while (x < bsq.x2)
	{
		if (bsq.s[bsq.y2 * bsq.len_y + x] == 'o')
			return (x);
		x += 1;
	}
	return (-1);
}

int	make_bsq_2(t_bsq *bsq)
{
	int	xo = -1;
	int	i = 0;

	bsq->x2 = bsq->x1 + 1;
	bsq->y2 = bsq->y1 + 1;
	while (bsq->x2 < bsq->len_x && bsq->y2 < bsq->len_y &&
	       (xo = check_o(*bsq)) == -1)
	{
		bsq->x2 += 1;
		bsq->y2 += 1;
		i += 1;
	}
	if (bsq->x2 - bsq->x1 > bsq->size)
	{
		bsq->size = bsq->x2 - bsq->x1;
		bsq->x = bsq->x1;
		bsq->y = bsq->y1;
	}
	if (xo <= 0)
		bsq->x1 += 1;
	else
		bsq->x1 = xo + 1;
	return (i);
}

int     make_bsq(t_bsq bsq)
{
	int   i;

	bsq.y1 = 0;
	while (bsq.y1 + bsq.size < bsq.len_y)
	{
		bsq.x1 = 0;
		while (bsq.x1 + bsq.size < bsq.len_x)
			i += make_bsq_2(&bsq);
		bsq.y1 += 1;
	}
	display_bsq(bsq);
	my_str("\e[01;39m", 1);
	my_str("\nSTEP = ", 1);
	my_put_nbr(i);
	my_str("\nPos = [", 1);
	my_put_nbr(bsq.y);
	my_str("][", 1);
	my_put_nbr(bsq.x);
	my_str("] ", 1);
	my_str("\nSize = ", 1);
	my_put_nbr(bsq.size);
	my_putchar('\n');
	free(bsq.s);
	return (0);
}
