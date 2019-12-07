/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:16:59 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/07 15:35:14 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

/*
**	Print table within its width and height that is represented by size
*/

void	print_table(int **table)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			ft_putchar(table[i][j] + '0');
		ft_putchar('\n');
	}
}

/*
**	LEAKS!!
*/

int		**init_table(int **table)
{
	int		c;

	c = 0;
	if (!(table = (int **)malloc(sizeof(int *) * (4 + 1))))
		return (NULL);
	while (c < 4)
		*(table + c++) = (int *)malloc(sizeof(int) * 4);
	*(table + c) = NULL;
	return (table);
}

/*
**	Amount values
*/

int		check_spot(int **table, int i, int j)
{
	int		res;

	res = 0;
	if (i < 4 - 1)
		res += table[i + 1][j] ? 1 : 0;
	if (i > 0)
		res += table[i - 1][j] ? 1 : 0;
	if (j < 4 - 1)
		res += table[i][j + 1] ? 1 : 0;
	if (j > 0)
		res += table[i][j - 1] ? 1 : 0;
	return (res - 1);
}

int		check_square_tetramino(int **table)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (table[i][j] != 0)
			{
				if (table[i][j] == 2 && table[i][j + 1] == 2 &&
					table[i + 1][j] == 2 && table[i + 1][j + 1] == 2)
					return (1);
				else
					return (0);
			}
		}
	}
	return (0);
}

int		check_tetraminos(int ***table)
{
	int		sum;
	int		i;
	int		j;

	i = -1;
	sum = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (*(*(*table + i) + j))
			{
				*(*(*table + i) + j) += check_spot(*table, i, j);
				sum += *(*(*table + i) + j);
			}
		}
	}
	if (sum == 6)
		return (1);
	else if (sum == 8)
		return (check_square_tetramino(*table));
	else
		return (0);
}

/*
** LEAKS INIT_TABLE
*/

int		check_input_with_table(int ***table, char *str, int *i, int *size)
{
	int	j;

	j = 0;
	if (*str && (ft_strlen(str) != 4 || (*i) == -1))
		return (0);
	if (!(*i) && !(*size))
		*table = init_table(*table);
	while (*str)
		if (*str++ == '#')
			*(*(*table + *i) + j++) = 1;
		else if (*(str - 1) == '.')
			*(*(*table + *i) + j++) = 0;
		else
			return (0);
	(*i)++;
	if (*i == 4)
	{
		(*size)++;
		print_table(*table);
		printf("\n");
		if (!check_tetraminos(table))
			return (0);
		*i = -1;
	}
	return (1);
}

/*
**	Each character must be either a block character(’#’)
**	or an empty character (’.’)
*/

int		check_input_data(char *file_name, int *size)
{
	char	*str;
	int		fd;
	int		i;
	int		**table;

	table = NULL;
	i = 0;
	if ((fd = open((const char *)file_name, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &str))
		if (!check_input_with_table(&table, str, &i, size))
			return (0);
	close(fd);
	return (1);
}

void	fill_double_array(char ***p_double_array, int *ar, char *str, int *i)
{
	int		j;

	j = -1;
	if (!(*str))
	{
		*i = 0;
		(*ar)++;
		*(ar + 1) = 0;
		return ;
	}
	while (str[++j])
	{
		if (str[j] == '#')
		{
			*(*(*p_double_array + *ar) + (*(ar + 1))++) = *i;
			*(*(*p_double_array + *ar) + (*(ar + 1))++) = j;
		}
	}
	(*i)++;
}

char	**second_pass(char *file_name, int amount)
{
	char	**double_array;
	int		fd;
	char	*str;
	int		i;
	int		array_coord[2];

	i = -1;
	array_coord[0] = 0;
	array_coord[1] = 0;
	if (!(double_array = (char **)malloc(sizeof(char) * (amount + 1))))
		return (NULL);
	while (++i < amount)
		*(double_array + i) = (char *)malloc(sizeof(char) * 8);
	*(double_array + i) = NULL;
	if ((fd = open((const char *)file_name, O_RDONLY)) == -1)
		return (NULL);
	i = 0;
	while (get_next_line(fd, &str))
		fill_double_array(&double_array, array_coord, str, &i);
	close(fd);
	return (double_array);
}

int		main(void)
{
	int		amount;
	char	file_name[] = "input.txt";
	char	**double_array;
	int		i;
	int		j;

	i = -1;
	j = -1;
	amount = 0;
	if (!check_input_data(file_name, &amount))
		ft_putstr("ERROR\n");
	else
		ft_putstr("SUCCESS\n");
	if (!(double_array = second_pass(file_name, amount)))
		printf("Error. Array of coordinates doesn't exist\n");
	else
	{
		while (double_array[++i])
		{
			j = -1;
			while (++j < 8)
				printf("%d ", double_array[i][j]);
			printf("\n");
		}
	}
	return (0);
}
