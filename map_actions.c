/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 21:31:08 by eshor             #+#    #+#             */
/*   Updated: 2019/12/23 16:01:43 by eshor            ###   ########.fr       */
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

short		*create_map(int size)
{
	short *map;
	int i;

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

void	print_charmap(char **map,  int map_size)
{
	int x;
	int y;

	y = 0;
	while (y < map_size)
	{
		x = 0;
		while (x < map_size)
		{
			ft_putchar(map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int		print_with_letters(t_lst *head, int map_size)
{
	int x;
	int y;
	char **letter_map;

	if (!(letter_map = ((char**)malloc(sizeof(char*) * map_size * map_size))))
		return (-1);
	y = -1;
	while (y++ < map_size)
	{
		if (!(letter_map[y] = (char*)malloc(sizeof(char) * map_size)))
			return (-1);
		x = -1;
		while (x++ < map_size)
			letter_map[y][x] = '.';	
	}
	while (head)
	{
		x = 0;
		while (x < 4)
		{
			letter_map[((head->coords)[x] + head->upperleft) / map_size][((head->coords)[x] + head->upperleft) % map_size] = 'A' + head->index_number;
			x++;
		}
		head = head->next;
	}
	print_charmap(letter_map, map_size);
	return (0);
}