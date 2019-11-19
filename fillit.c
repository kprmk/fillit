/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:16:59 by mbrogg            #+#    #+#             */
/*   Updated: 2019/11/19 21:46:10 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

/*
**	Print table within its width and height that is represents by size
*/
static	void	print_table(int **table, int size)
{
	int		i;
	int		j;

	i = -1;
	while(++i < size)
	{
		j = -1;
		while(++j < size)
			ft_putchar(table[i][j] + '0');
		ft_putchar('\n');
	}
}

static	int		**init_table(int **table, int size)
{
	int		c;

	c = 0;
	if (!(table = (int **)malloc(sizeof(int *) * (size + 1))))
		return (NULL);
	while(c < size)
		*(table + c++) = (int *)malloc(sizeof(int) * size);
	*(table + c) = NULL;
	return (table);
}

static int	check_spot(int	**table, int size, int i, int j)
{
	int		res;

	res = 0;
	if (i < size - 1)
		res += table[i + 1][j] ? 1 : 0;
	if (i > 0)
		res += table[i - 1][j] ? 1 : 0;
	if (j < size - 1)
		res += table[i][j + 1] ? 1 : 0;
	if (j > 0)
		res += table[i][j - 1] ? 1 : 0;
	return (res - 1);
}

static	int		check_tetriminos(int ***table, int size)
{
	int		sum;
	int		i;
	int		j;

	i = -1;
	sum = 0;
	while(++i < size)
	{
		j = -1;
		while(++j < size)
		{
			if (*(*(*table + i) + j))
			{
				*(*(*table + i) + j) += check_spot(*table, size, i , j);
				sum = *(*(*table + i) + j);
			}
		}
	}
	printf("~%d\n", sum);
	// print_table(*table, size);
	return (sum == 6 ? 1 : 0);
}

/*
** LEAKS IBIT_TABLE
*/
static	int		check_input_with_table(int	***table, char *str, int *i, int *size)
{
	int 	j;

	j = 0;
	if (!(*size) && !(*i))
		*size = ft_strlen(str);
	if (!(*table = init_table(*table, *size)))
		return (0);
	if (*str == '\0')
	{
		check_tetriminos(table, *size);
		*i = -1;
	}
	while(*str)
		if(*str++ == '#')
			*(*(*table + *i) + j++) = 1;
		else
			*(*(*table + *i) + j++) = 0;
	return (1);
}

/*
**	Each character must be either a block character(’#’)
**	or an empty character (’.’)
*/
int		check_input_data(char *file_name)
{
	char 	*str;
	int		size;
	int		fd;
	int		i;
	int		**table;

	table = NULL;
	size = 0;
	i = 0;
	if ((fd = open((const char *)file_name, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &str))
	{
		// ft_putstr_fd(str, fd_w);
		// ft_putchar_fd('\n', fd_w);
		if (!check_input_with_table(&table, str, &i, &size))
			return (0);
		i++;
		ft_putstr(str);
		ft_putchar('\n');
	}
	// print_table(table, 4);
	close(fd);
	return (1);
}

int main()
{
	if (!check_input_data("input.txt"))
		ft_putstr("ERROR\n");
	else
		ft_putstr("SUCCESS\n");
	
	return (0);
}
