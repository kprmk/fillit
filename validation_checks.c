/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:56:18 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/07 16:09:12 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
