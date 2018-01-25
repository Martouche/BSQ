/*
** get_file.c for get_file in /home/wery_a/rendu/BSQ/Test/v3
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Thu Jan 15 16:44:20 2015 adrien wery
** Last update Fri Jan 16 18:51:08 2015 adrien wery
*/

#include "bsq.h"

void    check_tab(char *s, int len_x, int len_y)
{
	int   i = 0;
	while (42)
	{
		if (s[i] != '.' && s[i] != 'o')
		{
			my_str("Invalid File !!!\n", 1);
			my_str("I have to replace '", 1);
			my_putchar(s[i]);
			my_str("' by '.' !!!\n", 1);
			s[i] = '.';
		}
		i += 1;
	}
	if (i != (len_x * len_y))
		my_error("Isn't a rectangle !!!");
}

int     get_len(int fd, t_bsq *bsq, char *buff)
{
	int   k = 0;
	int   i = 0;
	int   a = 1;

	while (a != 0)
	{
		buff = my_memset(buff, 0, BUFF_SIZE);
		a = read(fd, buff, BUFF_SIZE);
		k = 0;
		while (k < a)
		{
			if (i == 0)
				while (buff[k] && buff[k++] != '\n');
			if (buff[k] != '\n')
				i += 1;
			else
				bsq->len_y += 1;
			k += 1;
		}
	}
	close (fd);
	return (i);
}

void    get_tab(int fd, t_bsq *bsq, char *buff)
{
	int   a = 1;
	int   k;
	int   i = 0;

	while (a != 0)
	{
		buff = my_memset(buff, 0, BUFF_SIZE);
		a = read(fd, buff, BUFF_SIZE);
		k = 0;
		while (k < a)
		{
			if (i == 0)
				while (buff[k] && buff[k++] != '\n');
			if (buff[k] != '\n')
				bsq->s[i++] = buff[k];
			k += 1;
		}
	}
	bsq->s[i] = '\0';
	bsq->len_x = i / bsq->len_y;
	free (buff);
	close(fd);
}
