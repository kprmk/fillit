/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:53:40 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/21 19:53:35 by mbrogg           ###   ########.fr       */
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

char	fill_lst(t_lst **head, int *ar, char *str, int *i)
{
	int		j;

	j = -1;
	if (!(*str))
	{
		*i = 0;
		ar[0] = 0;
		return (1);
	}
	if (!(*i))
		if (!lst_push_front(head, lst_new(ar[1]++)))
			return (0);
	while (str[++j])
	{
		if (str[j] == '#')
		{
			(*head)->coords[ar[0]++] = *i;
			(*head)->coords[ar[0]++] = j;
			// *(*(*p_double_array + *ar) + (*(ar + 1))++) = *i;
			// *(*(*p_double_array + *ar) + (*(ar + 1))++) = j;
		}
	}
	(*i)++;
	return (1);
}

t_lst	*second_pass(char *file_name, t_lst **head)
{
	int		fd;
	char	*str;
	int		i;
	int		array[2];

	i = -1;
	array[0] = 0;
	array[1] = 0;
	if ((fd = open((const char *)file_name, O_RDONLY)) == -1)
		return (NULL);
	i = 0;
	while (get_next_line(fd, &str))
		fill_lst(head, array, str, &i);
	close(fd);
	return (*head);
}
