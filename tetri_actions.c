/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:01:55 by eshor             #+#    #+#             */
/*   Updated: 2020/01/13 16:10:55 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_push(short *map, int map_size, short *coord, int *r_l_cur)
{
	int i;
	int curr_pos;

	curr_pos = r_l_cur[2];
	i = 0;
	while (i < 4)
	{
		if (map[coord[i] + curr_pos] == 1)
			return (-1);
		i++;
	}
	if (coord[3] + curr_pos > map_size * map_size - 1)
		return (-1);
	if (curr_pos / map_size != ((coord[i] % map_size + curr_pos) / map_size))
		return (-1);
	if ((coord[0] + curr_pos) % map_size >= map_size - r_l_cur[0])
	{
		return (-1);
	}
	if (((coord[0] + curr_pos - r_l_cur[1]) % map_size >
	map_size - (r_l_cur[0] + r_l_cur[1] + 1)))
	{
		return (-1);
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
		(*map)[((*node)->coords)[i] + curr_pos] = 1;
		(*node)->upperleft = curr_pos;
		(*node)->index_number = num;
		i++;
	}
}

int		check_height(short *coords, int map_size)
{
	int i;
	int length;
	int min;
	int max;

	if (map_size > 3)
		return (map_size);
	i = 0;
	min = 15;
	max = 0;
	while (i < 4)
	{
		if (coords[i] > max)
			max = coords[i];
		if (coords[i] < min)
			min = coords[i];
		i++;
	}
	length = max % 4 - min % 4 + 1;
	if (length > map_size)
		return (length);
	else
		return (map_size);
}
