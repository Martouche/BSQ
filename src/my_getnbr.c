/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/


int	my_getnbr(char *str)
{
	int value = 0;
	int i = 0;

	while (str[i] < '0' || (str[i] > '9' && str[i] != '\0'))
		str = str + 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = ((10 * value) + (str[i] - 48));
		i = i + 1;
	}
	return (value);
}
