/*
** main.c for main in /home/wery_a/rendu/BSQ/Test
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Mon Jan 12 15:22:24 2015 adrien wery
** Last update Sun Jan 18 23:21:32 2015 adrien wery
*/

#include "bsq.h"

void    display_bsq(t_bsq bsq)
{
	int   x;
	int   y = 0;

	while (y < bsq.len_y)
	{
		x = 0;
		while (x < bsq.len_x)
		{
			if (y >= bsq.y && y < bsq.y + bsq.size &&
			    x >= bsq.x && x < bsq.x + bsq.size)
			{
				my_str("\e[01;31m", 1);
				bsq.s[y * bsq.len_y + x] = 'x';
			}
			else if (bsq.s[y * bsq.len_y + x] == 'o')
				my_str("\e[01;32m", 1);
			else
				my_str("\e[01;33m", 1);
			my_putchar(bsq.s[y * bsq.len_y + x]);
			x += 1;
		}
		y += 1;
		my_putchar('\n');
	}
}

int	main(int argc, char **argv)
{
	t_bsq	bsq;
	char	*buff;
	int	fd;
	int	i;

	if (argc != 2)
		my_error("Need only one argument : the file !!!");
	buff = my_malloc(BUFF_SIZE);
	bsq.x = bsq.y = bsq.len_y = bsq.x2 = bsq.y2 = bsq.size = 0;
	fd = my_open(argv[1]);
	i = get_len(fd, &bsq, buff);
	if (bsq.len_y < 3 || i < 10)
		my_error("File isn't accept !!!");
	fd = my_open(argv[1]);
	bsq.s = my_malloc(i + 1);
	get_tab(fd, &bsq, buff);
	check_tab(bsq.s, bsq.len_x, bsq.len_y);
	make_bsq(bsq);
	return (0);
}
