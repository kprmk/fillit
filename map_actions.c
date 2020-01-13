/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 21:31:08 by eshor             #+#    #+#             */
/*   Updated: 2020/01/13 13:32:27 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	delete_map(short **map)
{
	free(*map);
	*map = NULL;
}
