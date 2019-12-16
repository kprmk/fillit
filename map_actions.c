/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 21:31:08 by eshor             #+#    #+#             */
/*   Updated: 2019/12/16 18:01:23 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		print_map(char **map, int size)
{
	int i;
	int j;

	if (!map)
		return (-1);
	j = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	return (0);
}

char	**create_map(int size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	if (!(map = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (char*)malloc(sizeof(char*) * size)))
		{
			delete_map(&map, size);
			return (NULL);
		}
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	delete_map(char ***map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
	{
		free((*map)[i]);
		i++;
	}
	*map = NULL;
}
