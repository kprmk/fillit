/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:16:59 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/23 16:18:03 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			solve(short **map, int map_size, t_lst **node, int num)
{
	int curr_pos;

	curr_pos = 0;
	while (curr_pos != -1)
	{
		if (can_push_tetri(*map, map_size, (*node)->coords, curr_pos) == 0)
		{
			push_tetri(map, node, curr_pos, num);
//			print_map(*map, map_size);
			if ((*node)->next)
			{
				if ((can_tetri_be_in_map(*map, map_size, (*node)->next->coords)) == 0)
				{
					if ((solve(map, map_size, &((*node)->next), num + 1)) == 0)
						return (0);
					else
						clear_tetri(map, node, curr_pos);		
				}
				else
					clear_tetri(map, node, curr_pos);
			}
			else
				return (0);
		}
		curr_pos = find_next_upperleft(map_size, curr_pos);
	}
	return (-1);
}

void		bruteforce(t_lst *node,  int tetri_nbr)
{
	short	*map;
	int		j;
	int		map_size;
	t_lst	*temp;
	
	map_size = ft_sqrt(tetri_nbr * 4);
	map = create_map(map_size);
//	print_map(map, map_size);
	lst_foreach(node, (void (*)(void *))move_upleft);
	temp = node;
	while (temp)
	{
		change_map_size_for_coords(&(temp->coords), 4, map_size);
		temp = temp->next;
	}	
	j = -1;
	while (j == -1)
	{
		j = solve(&map, map_size, &node, 0);
		if (j == -1)
		{
			delete_map(&map);
			map_size++;
			map = create_map(map_size);
			temp = node;
			while (temp->next)
			{
				change_map_size_for_coords(&(temp->coords), map_size - 1, map_size);
				temp = temp->next;
			}
			printf("%s\n", "map too small");
		}
//		else
//			print_map(map, map_size);
	}
//	lst_print(node);
	print_with_letters(node, map_size);
}
