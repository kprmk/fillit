/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:16:59 by mbrogg            #+#    #+#             */
/*   Updated: 2020/01/14 16:19:53 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			solve(short **map, int map_size, t_lst **node, int num)
{
	int r_l_curr[3];

	r_l_curr[0] = (*node)->r;
	r_l_curr[1] = (*node)->l;
	r_l_curr[2] = 0;
	while (r_l_curr[2] < map_size * map_size - 3)
	{
		if (can_push(*map, map_size, (*node)->coords, r_l_curr) == 0)
		{
			push_tetri(map, node, r_l_curr[2], num);
			if ((*node)->next)
			{
				if ((solve(map, map_size, &((*node)->next), num + 1)) == 0)
					return (0);
				else
					clear_tetri(map, node, r_l_curr[2]);
			}
			else
				return (0);
		}
		r_l_curr[2]++;
	}
	return (-1);
}

void		bruteforce(t_lst *node, int tetri_nbr)
{
	short	*map;
	int		map_size;
	t_lst	*temp;

	map_size = ft_sqrt(tetri_nbr * 4);
	temp = node;
	while (temp)
	{
		map_size = check_height(temp->coords, map_size, temp->r, temp->l);
		temp = temp->next;
	}
	map = create_map(map_size);
	lst_foreach(node, (void (*)(void *))move_upleft);
	lst_print(node);
	change_size_for_lst(node, 4, map_size);
	lst_print(node);
	while (solve(&map, map_size, &node, 0) == -1)
	{
		delete_map(&map);
		map_size++;
		map = create_map(map_size);
		change_size_for_lst(node, map_size - 1, map_size);
		lst_print(node);
	}
	if (print_with_letters(node, NULL, map_size) == -1)
		ft_putstr("error\n");
	delete_map(&map);
}
