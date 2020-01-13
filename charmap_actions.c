/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charmap_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:26:11 by eshor             #+#    #+#             */
/*   Updated: 2020/01/13 22:51:23 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_charmap(char ***map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

void	print_charmap(char **map, int map_size)
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

char	**create_charmap(int size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	if (!(map = ((char**)malloc(sizeof(char*) * size * size))))
		return (NULL);
	while (i < size)
	{
		map[i] = (char*)malloc(sizeof(char) * size);
		if (!map[i])
		{
			delete_charmap(&map, i);
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

int		print_with_letters(t_lst *head, t_lst *cur, int size)
{
	int		amount;
	int		counter;
	int		x;
	char	**map;

	amount = amount_of_items(head, cur);
	counter = 0;
	map = create_charmap(size);
	while (head && counter++ <= amount)
	{
		x = 0;
		while (x < 4)
		{
			map[((head->coords)[x] + head->upperleft) / size][((head->
			coords)[x] + head->upperleft) % size] = 'A' + head->index_number;
			x++;
		}
		head = head->next;
	}
	print_charmap(map, size);
	delete_charmap(&map, size);
	return (0);
}
