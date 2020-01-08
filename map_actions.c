/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprmk <kprmk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 21:31:08 by eshor             #+#    #+#             */
/*   Updated: 2020/01/08 13:12:39 by kprmk            ###   ########.fr       */
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


void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

int		amount_of_items(t_lst *head, t_lst *cur)
{
	int counter;
	
	counter = 0;
	while (head != cur)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}

int		print_with_letters(t_lst *head, t_lst *cur, int map_size)
{
	int amount;
	int counter;
	// usleep(200000); // 200000
	int x;
	int y;
	char **letter_map;
	
	amount = amount_of_items(head, cur);
	counter = 0;
	ft_putstr("\e[1;1H\e[2J");
	//
	printf("Map size -> %d\n\n", map_size);
	//
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
	while (head && counter++ <= amount)
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