/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:53:40 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/16 16:18:11 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
//		print_table(*table);
//		printf("\n");
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
