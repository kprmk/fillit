/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 21:31:08 by eshor             #+#    #+#             */
/*   Updated: 2020/01/16 17:26:55 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Prints any pointer to short - one-dimensional array of short.
*/
int		print_map(short *map, int size)
{
	int i;
	int j;

	if (!map)
		return (-1);
	i = 0;
	j = 0;
	while (i < size * size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i] == 0)
				ft_putchar('.');
			else
				ft_putchar('#');
			i++;
			j++;
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
	return (0);
}

/*
** Creates pointer to short.
*/
short	*create_map(int size)
{
	short	*map;
	int		i;

	if (!(map = (short*)malloc(sizeof(short) * size * size)))
		return (NULL);
	i = 0;
	while (i < size * size)
	{
		map[i] = 0;
		i++;
	}
	return (map);
}
/*
** Deletes pointer to short.
*/
void	delete_map(short **map)
{
	free(*map);
	*map = NULL;
}
