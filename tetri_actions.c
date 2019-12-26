/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:01:55 by eshor             #+#    #+#             */
/*   Updated: 2019/12/23 16:21:54 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_push_tetri(short *map, int map_size, char *coord, int *curr_pos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (coord[i] > map_size * map_size - 1)
			return (-1);
		i++;
	}
	return (0);
}

void	clear_tetri(short **map, char *coord, int curr_pos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		(*map)[coord[i] + curr_pos] = 0;
		i++;
	}
}

void	push_tetri(short **map, char *coord, int curr_pos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		(*map)[coord[i] + curr_pos] = 1;
		i++;
	}
}


/*
int		can_tetri_be_in_map(char **map, int map_size, char *coord)
{
	int		i;
	int		j;
	int		*curr_xy;

	i = 0;
	j = 0;
	curr_xy = (int*)malloc(sizeof(int) * 2);
	if (!curr_xy)
		return (-2);
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			curr_xy[0] = j;
			curr_xy[1] = i;
			if (can_push_tetri(&map, map_size, coord, curr_xy) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (-1);
}
*/


int		find_next_upperleft(int map_size, int curr_pos)
{
	if (curr_pos >= map_size * map_size - 1)
		return (-1);
	curr_pos++;
	return (curr_pos);
}
