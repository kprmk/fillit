/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:01:55 by eshor             #+#    #+#             */
/*   Updated: 2019/12/16 21:34:00 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_push_tetri(char ***map, int map_size, char *coord, int *curr_xy)
{
	int i;
	int figure_x;
	int figure_y;
	int curr_x;
	int curr_y;

	i = 0;
	figure_x = 0;
	figure_y = 0;
	curr_x = curr_xy[0];
	curr_y = curr_xy[1];
	while (i < 8)
	{
		figure_x = coord[i + 1];
		figure_y = coord[i];
		if ((curr_x + figure_x >= map_size) || (curr_y + figure_y >= map_size))
			return (-1);
		if ((*map)[curr_y + figure_y][curr_x + figure_x] == '#')
			return (-1);
		i += 2;
	}
	return (0);
}

void	clear_tetri(char ***map, char *coord, int curr_x, int curr_y)
{
	int i;
	int figure_x;
	int figure_y;

	i = 0;
	figure_x = 0;
	figure_y = 0;
	while (i < 8)
	{
		figure_x = coord[i + 1];
		figure_y = coord[i];
		(*map)[curr_y + figure_y][curr_x + figure_x] = '.';
		i += 2;
	}
}

void	push_tetri(char ***map, char *coord, int curr_x, int curr_y)
{
	int i;
	int figure_x;
	int figure_y;

	i = 0;
	figure_x = 0;
	figure_y = 0;
	while (i < 8)
	{
		figure_x = coord[i + 1];
		figure_y = coord[i];
		(*map)[curr_y + figure_y][curr_x + figure_x] = '#';
		i += 2;
	}
}

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
/*
int		*find_next_upperleft(char **map, int map_size, int *curr_xy)
{
	int curr_x;
	int curr_y;

	curr_x = curr_xy[0];
	curr_y = curr_xy[1];
	if (curr_x == curr_y && curr_x == map_size - 1)
		return (NULL);
	if (curr_x == 0 && curr_y == 0)
		curr_x = 1;
	else if (curr_x == 0 && curr_y < map_size - 1)
	{
		curr_x = curr_y + 1;
		curr_y = 0;
	}
	else if (curr_y == map_size - 1)
	{
		curr_y = curr_x + 1;
		curr_x = map_size - 1;
		
	}
	else
	{
		curr_x--;
		curr_y++;
	}
	curr_xy[0] = curr_x;
	curr_xy[1] = curr_y;
	return (curr_xy);
}
*/

int		*find_next_upperleft(int map_size, int *curr_xy)
{
	int curr_x;
	int curr_y;

	curr_x = curr_xy[0];
	curr_y = curr_xy[1];
	if (curr_x == curr_y && curr_x == map_size - 1)
		return (NULL);
	if (curr_x == map_size - 1)
	{
		curr_x = 0;
		curr_y++;
	}
	else
	{
		curr_x++;
	}
	curr_xy[0] = curr_x;
	curr_xy[1] = curr_y;
	return (curr_xy);
}
