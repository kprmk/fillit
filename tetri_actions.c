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

int		can_push_tetri(short *map, int map_size, short *coord, int curr_pos)
{
	int i;
	int str_num;

	i = 0;
	while (i < 4)
	{
		if (coord[i] + curr_pos  > map_size * map_size - 1)
			return (-1);
		if ( curr_pos / map_size != ((coord[i] % map_size + curr_pos) / map_size))
			return (-1);
		if (map[coord[i] + curr_pos] == 1)
			return (-1);
		i++;
	}
	return (0);
}

void	clear_tetri(short **map, t_lst **node, int curr_pos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		(*map)[((*node)->coords)[i] + curr_pos] = 0;
		i++;
	}
}

void	push_tetri(short **map, t_lst **node, int curr_pos, int num)
{
	int i;

	i = 0;
	while (i < 4)
	{
		(*map)[((*node)->coords)[i]  + curr_pos] = 1;
		(*node)->upperleft = curr_pos;
		(*node)->index_number = num;
		i++;
	}
}

int		can_tetri_be_in_map(short *map, int map_size, short *coord)
{
	int		i;
	int		*curr_xy;

	i = 0;
	while (i < map_size * map_size - 1)
	{
		if (can_push_tetri(map, map_size, coord, i) == 0)
			return (0);
		i++;
	}
	return (-1);
}

int		find_next_upperleft(int map_size, int curr_pos)
{
	if (curr_pos >= map_size * map_size - 1)
		return (-1);
	curr_pos++;
	return (curr_pos);
}
